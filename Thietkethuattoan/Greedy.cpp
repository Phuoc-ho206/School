#include <iostream>
#include <vector>
#include <chrono>
using namespace std;

int n;
int cost = 0;
int C[100][100];
vector<int> path;
vector<bool> visited; // true:da xet, false:chua xet
void greedy()
{
    int curr = 0;
    visited[0] = true;
    path.push_back(0);
    for (int k = 1; k < n; k++)
    {
        int min = 1e9;
        int next = -1;
        for (int i = 0; i < n; i++)
        {
            if (!visited[i] && C[curr][i] < min)
            {
                min = C[curr][i];
                next = i;
            }
        }
        visited[next] = true;
        cost += C[curr][next];
        curr = next;
        path.push_back(curr);
    }
    cost += C[curr][0];
    path.push_back(0);
}
void print_time()
{
    auto start = chrono::high_resolution_clock::now();
    greedy();
    auto end = chrono::high_resolution_clock::now();
    auto time_ms = chrono::duration_cast<chrono::milliseconds>(end - start);
    cout << "Thoi gian: " << time_ms.count() << " ms\n";
}
int main()
{
    cin >> n;
    visited.resize(n + 1, false);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> C[i][j];
        }
    }
    greedy();
    cout << "======GREEDY=======" << endl;
    cout << "Chi phi: " << cost << endl;
    for (int i = 0; i < path.size(); i++)
    {
        cout << path[i] << "--->";
    }
    cout << endl;
    print_time();
}
