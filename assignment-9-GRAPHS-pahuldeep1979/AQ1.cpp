/*
A graph G is defined as a pair (V, E) where V is a set of nodes/vertices and E is a set of edges connecting
pairs of vertices. Graphs may be directed or undirected and may have weighted or unweighted edges.
They can be represented using an adjacency matrix, adjacency list, or edge list.

Write a program to implement the following graph algorithms:
1. Breadth First Search (BFS)
2. Depth First Search (DFS)
3. Minimum Spanning Tree (Kruskal and Prim)
4. Dijkstra's Shortest Path Algorithm
*/
#include <bits/stdc++.h>
using namespace std;

struct Edge {
    int u, v;
    int w;
    Edge(int _u=0,int _v=0,int _w=0):u(_u),v(_v),w(_w){}
};

// ---------- GRAPH (undirected, weighted) ----------
struct Graph {
    int n; // number of vertices (0..n-1)
    vector<vector<pair<int,int>>> adj; // (neighbor, weight)
    vector<Edge> edges; // edge list
    Graph(int n=0): n(n), adj(n) {}

    void addEdge(int u, int v, int w) {
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
        edges.emplace_back(u,v,w);
    }
};

// ---------- 1) BFS ----------
vector<int> BFS(const Graph &G, int src) {
    vector<int> order;
    vector<bool> vis(G.n,false);
    queue<int> q;
    q.push(src); vis[src]=true;
    while(!q.empty()){
        int u=q.front(); q.pop();
        order.push_back(u);
        for(auto [v,w] : G.adj[u]){
            if(!vis[v]){
                vis[v]=true;
                q.push(v);
            }
        }
    }
    return order;
}

// ---------- 2) DFS (recursive) ----------
void dfsRec(const Graph &G, int u, vector<bool>&vis, vector<int>&order) {
    vis[u]=true;
    order.push_back(u);
    for(auto [v,w] : G.adj[u]){
        if(!vis[v]) dfsRec(G, v, vis, order);
    }
}
vector<int> DFS(const Graph &G, int src) {
    vector<int> order;
    vector<bool> vis(G.n,false);
    dfsRec(G, src, vis, order);
    return order;
}

// ---------- Union-Find for Kruskal ----------
struct DSU {
    int n;
    vector<int> parent, rankv;
    DSU(int n=0): n(n), parent(n), rankv(n,0) {
        iota(parent.begin(), parent.end(), 0);
    }
    int find(int x){
        if(parent[x]==x) return x;
        parent[x] = find(parent[x]);
        return parent[x];
    }
    bool unite(int a,int b){
        a = find(a); b = find(b);
        if(a==b) return false;
        if(rankv[a] < rankv[b]) swap(a,b);
        parent[b] = a;
        if(rankv[a]==rankv[b]) rankv[a]++;
        return true;
    }
};

// ---------- 3a) Kruskal's MST ----------
pair<vector<Edge>, long long> kruskalMST(Graph G) {
    vector<Edge> res;
    long long total = 0;
    sort(G.edges.begin(), G.edges.end(), [](const Edge &a, const Edge &b){
        return a.w < b.w;
    });
    DSU dsu(G.n);
    for(const Edge &e : G.edges) {
        if(dsu.unite(e.u, e.v)) {
            res.push_back(e);
            total += e.w;
            if((int)res.size() == G.n-1) break;
        }
    }
    return {res, total};
}

// ---------- 3b) Prim's MST (using min-heap) ----------
pair<vector<Edge>, long long> primMST(const Graph &G, int start=0) {
    vector<bool> used(G.n,false);
    // min-heap of (weight, u, parent)
    using T = tuple<int,int,int>;
    priority_queue<T, vector<T>, greater<T>> pq;
    // push start with parent -1
    pq.push({0, start, -1});
    vector<Edge> res;
    long long total = 0;
    while(!pq.empty() && (int)res.size() < G.n-1) {
        auto [w,u,parent] = pq.top(); pq.pop();
        if(used[u]) continue;
        used[u] = true;
        if(parent != -1) {
            res.emplace_back(parent, u, w);
            total += w;
        }
        for(auto [v,wt] : G.adj[u]) {
            if(!used[v]) pq.push({wt, v, u});
        }
    }
    return {res, total};
}

// ---------- 4) Dijkstra's shortest path ----------
vector<long long> dijkstra(const Graph &G, int src) {
    const long long INF = (1LL<<60);
    vector<long long> dist(G.n, INF);
    dist[src] = 0;
    using P = pair<long long,int>; // (dist, node)
    priority_queue<P, vector<P>, greater<P>> pq;
    pq.push({0,src});
    while(!pq.empty()){
        auto [d,u] = pq.top(); pq.pop();
        if(d > dist[u]) continue;
        for(auto [v,w] : G.adj[u]){
            long long nd = d + w;
            if(nd < dist[v]){
                dist[v] = nd;
                pq.push({nd, v});
            }
        }
    }
    return dist;
}

// ---------- Utility: print edges ----------
void printEdgeList(const vector<Edge>& edges) {
    for(auto &e : edges) {
        cout << e.u << " - " << e.v << " (w=" << e.w << ")\n";
    }
}

// ---------- SAMPLE DEMO ----------
int main(){
    // Build sample graph with 6 nodes (0..5)
    // Edges:
    // 0-1 (4), 0-2 (3), 1-2 (1), 1-3 (2), 2-3 (4),
    // 3-4 (2), 4-5 (6), 2-5 (7), 1-4 (3)

    Graph G(6);
    G.addEdge(0,1,4);
    G.addEdge(0,2,3);
    G.addEdge(1,2,1);
    G.addEdge(1,3,2);
    G.addEdge(2,3,4);
    G.addEdge(3,4,2);
    G.addEdge(4,5,6);
    G.addEdge(2,5,7);
    G.addEdge(1,4,3);

    cout << "Graph (adjacency list):\n";
    for(int u=0; u<G.n; ++u){
        cout << u << ": ";
        for(auto [v,w] : G.adj[u]) cout << "(" << v << "," << w << ") ";
        cout << "\n";
    }
    cout << "\n";

    // 1) BFS from 0
    cout << "1) BFS order starting from 0:\n";
    auto bfs_order = BFS(G, 0);
    for(int x : bfs_order) cout << x << " ";
    cout << "\n\n";

    // 2) DFS from 0
    cout << "2) DFS (recursive) order starting from 0:\n";
    auto dfs_order = DFS(G, 0);
    for(int x : dfs_order) cout << x << " ";
    cout << "\n\n";

    // 3) MST: Kruskal
    cout << "3a) Kruskal's MST:\n";
    auto [kr_edges, kr_cost] = kruskalMST(G);
    printEdgeList(kr_edges);
    cout << "Total weight (Kruskal): " << kr_cost << "\n\n";

    // 3b) Prim's MST
    cout << "3b) Prim's MST (starting at 0):\n";
    auto [pr_edges, pr_cost] = primMST(G, 0);
    printEdgeList(pr_edges);
    cout << "Total weight (Prim): " << pr_cost << "\n\n";

    // 4) Dijkstra from 0
    cout << "4) Dijkstra shortest paths from 0:\n";
    auto dist = dijkstra(G, 0);
    for(int i=0;i<G.n;++i) {
        cout << "dist[0 -> " << i << "] = ";
        if(dist[i] >= (1LL<<60)) cout << "INF\n";
        else cout << dist[i] << "\n";
    }
    cout << "\n";

    return 0;
}

/*
Graph (adjacency list):
0: (1,4) (2,3)
1: (0,4) (2,1) (3,2) (4,3)
2: (0,3) (1,1) (3,4) (5,7)
3: (1,2) (2,4) (4,2)
4: (3,2) (5,6) (1,3)
5: (4,6) (2,7)

1) BFS order starting from 0:
0 1 2 3 4 5

2) DFS (recursive) order starting from 0:
0 1 2 3 4 5

3a) Kruskal's MST:
1 - 2 (w=1)
1 - 3 (w=2)
3 - 4 (w=2)
0 - 2 (w=3)
4 - 5 (w=6)
Total weight (Kruskal): 14

3b) Prim's MST (starting at 0):
0 - 2 (w=3)
2 - 1 (w=1)
1 - 3 (w=2)
3 - 4 (w=2)
4 - 5 (w=6)
Total weight (Prim): 14

4) Dijkstra shortest paths from 0:
dist[0 -> 0] = 0
dist[0 -> 1] = 4
dist[0 -> 2] = 3
dist[0 -> 3] = 6
dist[0 -> 4] = 7
dist[0 -> 5] = 10

*/