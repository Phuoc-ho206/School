#include <iostream>
#include <vector>
#include <chrono>

using namespace std;

int n;
int Cost[20][20];
vector<int>currpath;
vector<int>bestpath;
bool visited[20];
int min_cost=1e9;
void nhapmang()
{
    for (int i=0;i<n;i++)
    {
        for (int j=0;j<n;j++)
        {
            cin>>Cost[i][j];
        }
    }
}
void init()
{
    for (int i=0;i<n;i++)
    {
        visited[i]=false;
    }
    currpath.push_back(0);
    visited[0]=1;
}
void backtracking(int currCity, int pos,int cost)
{
    if(cost>=min_cost) return;
    if (pos==n)
    {
        cost+=Cost[currCity][0];
        if(cost<min_cost)
        {
            min_cost=cost;
            bestpath=currpath;
            bestpath.push_back(0);
        }
        return;
    }
    for (int i=1;i<n;i++)
    {
        if(!visited[i])
        {
            visited[i]=true;
            currpath.push_back(i);
            backtracking(i,pos+1,cost+Cost[currCity][i]);
            currpath.pop_back();
            visited[i]=false;
        }
    }

}
void print_path()
{
    for (int i=0;i<bestpath.size();i++)
    {
        if(i==bestpath.size()-1) cout<<bestpath[i];
        else cout<<bestpath[i]<<"--->";
    }
}
void print_time()
{
    auto start = chrono::high_resolution_clock::now();
    backtracking(0,1,0);
    auto end = chrono::high_resolution_clock::now();
    auto time_ms = chrono::duration_cast<chrono::milliseconds>(end - start);
    cout << "Thoi gian: " << time_ms.count() << " us\n";
}
int main()
{
    cin>>n;
    nhapmang();
    init();
    backtracking(0,1,0);
    cout<<"========BACKTRACKING======="<<endl;
    cout<<"Lo phi toi thieu: "<<min_cost<<endl;
    cout<<"Lo trinh: ";print_path();
    cout<<endl;
    print_time();

}