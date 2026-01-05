#include <iostream>
#include <vector>
#include <ctime> // dùng clock() để đo thời gian

using namespace std;

int n;
vector<vector<int>> Cost;
vector<int> currpath, bestpath;
vector<bool> visited;
int min_cost = 1000000000; // thay cho numeric_limits<int>::max()

void nhapmang()
{
    Cost.assign(n, vector<int>(n));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> Cost[i][j];
}

void init()
{
    visited.assign(n, false);
    currpath.clear();
    currpath.push_back(0);
    visited[0] = true;
}

void backtracking(int currCity, int pos, int cost)
{
    if (cost >= min_cost)
        return;

    if (pos == n)
    {
        cost += Cost[currCity][0];
        if (cost < min_cost)
        {
            min_cost = cost;
            bestpath = currpath;
            bestpath.push_back(0);
        }
        return;
    }

    for (int i = 1; i < n; i++)
    {
        if (!visited[i])
        {
            visited[i] = true;
            currpath.push_back(i);
            backtracking(i, pos + 1, cost + Cost[currCity][i]);
            currpath.pop_back();
            visited[i] = false;
        }
    }
}

void print_path()
{
    for (size_t i = 0; i < bestpath.size(); i++)
    {
        cout << bestpath[i];
        if (i != bestpath.size() - 1)
            cout << " ---> ";
    }
    cout << endl;
}

int main()
{
    cout << "Nhap so thanh pho: ";
    cin >> n;
    nhapmang();
    init();

    clock_t start = clock();
    backtracking(0, 1, 0);
    clock_t end = clock();

    double time_sec = double(end - start) / CLOCKS_PER_SEC;

    cout << "\n======== BACKTRACKING ========\n";
    cout << "Chi phi toi thieu: " << min_cost << endl;
    cout << "Lo trinh: ";
    print_path();
    cout << "Thoi gian thuc thi: " << time_sec << " giay\n";
}
