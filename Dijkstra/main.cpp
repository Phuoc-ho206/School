#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
using namespace std;

int n,m;
vector<vector<pair<int,int>>>adj;
void Dijkstra(int s,int t)
{
    vector<int>pre(n+1,-1);// O(V)
    vector<int>dist(n+1,1e9);//O(V)
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
    dist[s]=0;
    pq.push({0,s});// O(logV)
    while(!pq.empty())//O(V)
    {
        pair<int,int>q=pq.top();// O(1)
        int u=q.second;
        int kc=q.first;
        pq.pop();// O(logV)
        if(kc>dist[u]) continue;
        for (auto i : adj[u])// O(E)
        {
            int v= i.first;
            int len=i.second;
            if(dist[v]>len+dist[u])
            {
                dist[v]=dist[u]+len;
                pq.push({dist[v],v});// O(logV)
                pre[v]=u;
            }
        }
    }
    vector<int> path;
    cout<<"dist"<<"["<<t<<"]"<<" ="<<dist[t]<<endl;
    while(t!=-1)
    {
        if (dist[t] == 1e9) 
        {
            cout << "No path\n";
            return;
        }
        path.push_back(t);
        t=pre[t];
    }
    
    for (int i=path.size()-1;i>=0;i--)
    {
        if(i>=0 && i!=path.size()-1) cout<<"->";
        cout<<path[i];
    }

}


int main()
{
    int u,v,w;
    cin>>n>>m;
    adj.resize(n+1);
    for (int i=0;i<m;i++)
    {
        cin>>u>>v>>w;
        adj[u].push_back(make_pair(v,w));
        adj[v].push_back(make_pair(u,w));
    }
    Dijkstra(1,8);

}