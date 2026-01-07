#include <iostream>
#include <vector>
#include <chrono>
using namespace std;

int dp[1 << 20][20];
int cost[20][20];
int n;
int parent[1 << 20][20];
int max_mask;
void init()
{
    max_mask = (1 << n);
    for (int i = 0; i < max_mask; i++)
    {
        for (int j = 0; j < n; j++)
        {
            dp[i][j] = 1e9;
        }
    }
    dp[1 << 0][0] = 0;
}
void nhapmang()
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> cost[i][j];
        }
    }
}
void DP()
{
    for (int mask = 0; mask < max_mask; mask++)
    {
        for (int u = 0; u < n; u++)
        {
            if (!(mask & (1 << u)))
                continue;

            for (int v = 0; v < n; v++)
            {
                if (!(mask & (1 << v)))
                {
                    int newmask = mask | (1 << v);
                    if (dp[newmask][v] > dp[mask][u] + cost[u][v])
                    {
                        dp[newmask][v] = dp[mask][u] + cost[u][v];
                        parent[newmask][v] = u;
                    }
                }
            }
        }
    }
}
void print_path()
{
    int min_cost = 1e9;
    int end = -1;
    int mask = max_mask - 1;
    for (int i = 1; i < n; i++)
    {
        if (dp[max_mask - 1][i] + cost[i][0] < min_cost)
        {
            min_cost = dp[max_mask - 1][i] + cost[i][0];
            end = i;
        }
    }
    vector<int> path;
    while (mask != 1)
    {
        path.push_back(end);
        int p = parent[mask][end];
        mask = mask ^ (1 << end);
        end = p;
    }
    path.push_back(0);
    cout << min_cost << endl;
    for (int i = path.size() - 1; i >= 0; i--)
    {
        if (i > 0)
        {
            cout << path[i] << "--->";
        }
        else
        {
            cout << path[i] << "--->" << 0;
        }
    }
}
void print_time()
{
    auto start = chrono::high_resolution_clock::now();
    DP();
    auto end = chrono::high_resolution_clock::now();
    auto time_ms = chrono::duration_cast<chrono::milliseconds>(end - start);
    cout << "Thoi gian: " << time_ms.count() << " us\n";
}
int main()
{
    cin >> n;
    nhapmang();
    init();
    DP();
    print_path();
    cout << endl;
    print_time();
    return 0;
}