#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <queue>
using namespace std;

int n, m;

class Grap
{
public:
    int V;
    // Adjacency List
    vector<vector<pair<int, int>>> adj; // danh sách cạnh xuất phát từ u
                                        // pair<int, int>.first: Đỉnh kề
                                        // pair<int, int>.secind: Trọng số cạnh
};

class subgrap
{
public:
    vector<int> nodes;    // mảng lưu ds các đỉnh trong 1 cụm
    vector<int> gateways; // lưu ds các đỉnh trong cụm có cạnh nối sang cụm khác
};

// Tìm đường đi ngắn nhất từ s đến all đỉnh
pair<vector<int>, vector<int>> Dijkstra(Grap &G, int s)
{
    vector<int> dist(G.V + 1, 1e9); // lưu khoảng cách ngắn nhất từ s -> v trong đồ thị G có V đỉnh, khoảng cách ban đầu là 1e9 (INF)
    vector<int> pre(G.V + 1, -1);   // lưu info để truy vết đường đi ngắn nhất

    priority_queue<pair<int, int>,         // mỗi phần tử có dạng (khoảng cách, đỉnh)
                   vector<pair<int, int>>, // cấu trúc dữ liệu trong queue
                   greater<pair<int, int>> // so sánh để lấy ra phần tử có khoảng cách min
                   >
        pq;

    //* Hàng đợi ưu tiên (priority-queue): tự động so sánh để đưa giá trị có độ ưu tiên cao nhất lên top
    // (dist) và mỗi lần pop sẽ luôn lấy giá trị có độ ưu tiên cao nhất ra trc.

    // luu {dist,ver}
    dist[s] = 0;
    pq.push({0, s});
    while (!pq.empty())
    {
        pair<int, int> q = pq.top();
        pq.pop();
        if (q.first > dist[q.second])
            continue;
        for (int i = 0; i < G.adj[q.second].size(); i++)
        {
            int w = G.adj[q.second][i].first;
            int len = G.adj[q.second][i].second;
            if (dist[w] > len + dist[q.second])
            {
                dist[w] = len + dist[q.second];
                pq.push({dist[w], w});
                pre[w] = q.second;
            }
        }
    }
    return {dist, pre};
}

// chia cum
vector<subgrap> Chiacum(Grap &G, int k)
{
    vector<subgrap> clusters(k); // lưu ds các cụm chứa các đỉnh của đồ thị
    for (int u = 1; u <= G.V; u++)
    {
        int index = u % k;

        clusters[index].nodes.push_back(u); // push vào cluster các đỉnh của đồ thị
    }
    for (int c = 0; c < k; c++) // duyệt cụm c
    {
        for (int u : clusters[c].nodes) // duyệt từng đỉnh u của c
        {
            for (auto e : G.adj[u]) // duyệt tất cả các đỉnh kề u
            {
                int v = e.first;
                if (v % k != c) // kiểm tra xem đỉnh kề v thuộc cụm khác hay k
                {
                    clusters[c].gateways.push_back(u);
                }
            }
        }
    }
    return clusters;
}

// Xây dựng đồ thị chỉ có gateway
Grap reducegrap(Grap &G, vector<subgrap> &clusters, map<int, int> &newindex)
{
    Grap R;  // Khai báo đồ thị mới R
    R.V = 0; // Khởi tạo đỉnh của R = 0

    // Giữ lại các gateway
    for (subgrap &C : clusters) // duyệt từng cụm trong clusters
    {
        for (int g : C.gateways) // duyệt từng gateway của cụm C
        {
            newindex[g] = ++R.V; // với mỗi gateway tạo 1 đỉnh mới trong R
        }
    }
    R.adj.resize(R.V + 1); // Xác định lại phạm vi của ds kề cho đồ thị R

    // Giữ lại các cạnh giữa các gateway
    for (subgrap &C : clusters) // duyệt từng cụm trong clusters
    {
        for (int u : C.gateways) // duyệt từng gateway của cụm C
        {
            for (pair<int, int> e : G.adj[u]) // mỗi gateway duyệt từng cạnh kề của nó trong đồ thi G
            {
                int v = e.first;       // Đỉnh kề
                int w = e.second;      // Trọng số cạnh u-v
                if (newindex.count(v)) // kiểm tra v có là gateway trong R k
                {
                    // Ánh xạ u, v vào u2, v2 trong R
                    int u2 = newindex[u];
                    int v2 = newindex[v];
                    // Thêm cạnh
                    R.adj[u2].push_back({v2, w});
                }
            }
        }
    }
    return R;
}

// Tìm gateway ngắn nhất với đỉnh x trong cụm
int find_bestgateway(vector<subgrap> &cluster, map<pair<int, int>, vector<int>> &distInside, int x, int k)
{
    int min_x = 1e9;        // Lưu khoảng cách min từ x - gateway
    int bestgateway_X = -1; // Lưu gateway gần x nhất

    // Tìm gateway tối ưu nhất để đi từ x ra ngoài cụm
    for (int g : cluster[x % k].gateways) // Duyệt từng gateway g trong cụm x, (x % k để tìm cụm x thuộc về)
    {
        int dist = distInside[{x % k, g}][x]; // lấy khoảng cách min từ gateway g tới đỉnh x trong 1 cụm

        if (dist < min_x) // kiểm tra tìm khoảng cách min
        {
            // Cập nhật lại biến
            min_x = dist;
            bestgateway_X = g;
        }
    }
    return bestgateway_X;
}

// Truy vết(pre, x)
vector<int> getpath(vector<int> &pre, int x)
{
    vector<int> path;
    while (x != -1) // lặp đến đỉnh nguồn
    {
        path.push_back(x); // thêm đỉnh
        x = pre[x];        // quay lại đỉnh trc
    }
    // đảo lại thứ tự vì bây h đang là từ đích tới nguồn
    reverse(path.begin(), path.end());
    return path;
}

// Hàm chính
vector<int> Dive(Grap &G, int s, int t, int k)
{
    vector<subgrap> cluster = Chiacum(G, k); // chia cum
    map<pair<int, int>, vector<int>> distInside;
    // key:(cum thu k,gateway_x),value: danh sach tu gateway_x->moi nodes trong cum
    //  tim duong ngan nhat trong tung cum
    for (int i = 0; i < k; i++)
    {
        for (int g : cluster[i].gateways)
        {
            pair<vector<int>, vector<int>> d = Dijkstra(G, g);
            distInside[{i, g}] = d.first;
        }
    }
    if (cluster[s % k].nodes[s] == cluster[t % k].nodes[t])
    {
        auto dist = Dijkstra(G, s);
        vector<int> path = getpath(dist.second, t);
        return path;
    }
    else
    {
        //***muc tieu lay danh sach duong ngan nhat tu gateway toi s trong 1 cum
        // tim bestgateway_s
        int best_gateway_s = find_bestgateway(cluster, distInside, s, k);
        // tinh ngan nhat s->bestgateway_s va luu duong di
        auto s_bestgateway_s = Dijkstra(G, s);
        vector<int> path_s = getpath(s_bestgateway_s.second, best_gateway_s);
        // tuong tu voi t
        int best_gateway_t = find_bestgateway(cluster, distInside, t, k);
        auto t_bestgateway_t = Dijkstra(G, best_gateway_t);
        vector<int> path_t = getpath(t_bestgateway_t.second, t);
        // tinh ngan nhat bestgateway_s->bestgateway_t
        map<int, int> newindex;
        Grap R = reducegrap(G, cluster, newindex);
        // Chuyển chỉ số đỉnh từ đồ thị G sang R
        int new_bestS = newindex[best_gateway_s];
        int new_bestT = newindex[best_gateway_t];

        auto dist_bestS = Dijkstra(R, new_bestS);
        vector<int> pathMid = getpath(dist_bestS.second, new_bestT);

        //**Ghép thành đường đi hoàn chỉnh
        // Ánh xạ đường đi ngắn nhất tìm đc trên đồ thị rút gọn R
        map<int, int> oldindex;
        for (auto i : newindex)
        {
            oldindex[i.second] = i.first;
        }
        for (auto &i : pathMid)
        {
            i = oldindex[i];
        }
        // Ghép các đoạn thành fullpath r trả về
        vector<int> fullpath;
        for (int i = 0; i < path_s.size() - 1; i++)
        {
            fullpath.push_back(path_s[i]);
        }
        for (int i = 0; i < pathMid.size() - 1; i++)
        {
            fullpath.push_back(pathMid[i]);
        }
        for (int i = 0; i < path_t.size(); i++)
        {
            fullpath.push_back(path_t[i]);
        }
        return fullpath;
    }
    return {};
}
int main()
{
    int u, v, w, k;
    cin >> n >> m >> k;
    Grap G;
    G.V = n;
    G.adj.resize(n + 1);
    for (int i = 0; i < m; i++)
    {
        cin >> u >> v >> w;
        G.adj[u].push_back(make_pair(v, w));
        G.adj[v].push_back(make_pair(u, w));
    }
    vector<int> path = Dive(G, 1, 2, k);
    for (int i = 0; i < path.size(); i++)
    {
        if (i > 0)
            cout << "->";
        cout << path[i];
    }
    return 0;
}