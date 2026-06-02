#include <iostream>
#include <queue>
#include <vector>
using namespace std;

// Basic implementation: adjacency list graph.
vector<vector<int>> buildGraph(int n, const vector<pair<int, int>>& edges) {
    vector<vector<int>> g(n);
    for (auto [u, v] : edges) {
        g[u].push_back(v);
        g[v].push_back(u);
    }
    return g;
}

// Sample Problem 1: BFS traversal from source.
// Approach: Queue-based level expansion with visited array.
vector<int> bfs(int src, const vector<vector<int>>& g) {
    vector<int> order;
    vector<bool> vis(g.size(), false);
    queue<int> q;
    q.push(src);
    vis[src] = true;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        order.push_back(u);
        for (int v : g[u]) {
            if (!vis[v]) {
                vis[v] = true;
                q.push(v);
            }
        }
    }
    return order;
}

// Sample Problem 2: DFS traversal.
// Approach: Recursive depth-first exploration.
void dfsUtil(int u, const vector<vector<int>>& g, vector<bool>& vis, vector<int>& order) {
    vis[u] = true;
    order.push_back(u);
    for (int v : g[u]) {
        if (!vis[v]) dfsUtil(v, g, vis, order);
    }
}

vector<int> dfs(int src, const vector<vector<int>>& g) {
    vector<int> order;
    vector<bool> vis(g.size(), false);
    dfsUtil(src, g, vis, order);
    return order;
}

// Sample Problem 3: Count connected components.
// Approach: Run DFS/BFS from each unvisited node.
int connectedComponents(const vector<vector<int>>& g) {
    int comps = 0;
    vector<bool> vis(g.size(), false);
    for (int i = 0; i < (int)g.size(); i++) {
        if (!vis[i]) {
            comps++;
            vector<int> order;
            dfsUtil(i, g, vis, order);
        }
    }
    return comps;
}

int main() {
    int n = 6;
    vector<pair<int, int>> edges = {{0, 1}, {0, 2}, {1, 3}, {4, 5}};
    vector<vector<int>> g = buildGraph(n, edges);

    vector<int> bfsOrder = bfs(0, g);
    cout << "BFS from 0: ";
    for (int x : bfsOrder) cout << x << " ";
    cout << "\n";

    vector<int> dfsOrder = dfs(0, g);
    cout << "DFS from 0: ";
    for (int x : dfsOrder) cout << x << " ";
    cout << "\n";

    cout << "Connected components: " << connectedComponents(g) << "\n";
    return 0;
}
