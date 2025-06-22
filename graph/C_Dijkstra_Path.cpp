/*
Problem: C. Dijkstra?
Topic: Graphs, Shortest Path using Set
URL: https://codeforces.com/problemset/problem/20/C
Date: 2025-06-22
Author: Mohit Assudani
*/

#include <bits/stdc++.h>
using namespace std;

#define FIO ios::sync_with_stdio(false); cin.tie(0);
typedef pair<int, int> pii;
const int INF = 1e9;

int n, m;
vector<vector<pii>> adj; // Adjacency list: adj[u] = {v, weight}

// Dijkstra's Algorithm with path reconstruction
vector<int> dijkstra(int src, vector<int>& parent) {
    set<pii> s; // {distance, node}
    vector<int> dist(n + 1, INF); // 1-based indexing
    dist[src] = 0;
    parent[src] = -1;

    s.insert({0, src}); // Start from source

    while (!s.empty()) {
        auto it = s.begin();       // Get node with smallest distance
        int u = it->second;        // Current node
        s.erase(it);               // Mark as visited

        // Explore neighbors of u
        for (pii e : adj[u]) {
            int v = e.first;       // Neighbor node
            int w = e.second;      // Weight of edge u-v

            // Relaxation step
            if (dist[u] + w < dist[v]) {
                s.erase({dist[v], v});  // Remove old value if exists
                dist[v] = dist[u] + w;  // Update distance
                parent[v] = u;          // Store path
                s.insert({dist[v], v}); // Re-insert with updated distance
            }
        }
    }

    return dist;
}

int main() {
    FIO;

    cin >> n >> m;
    adj.resize(n + 1); // Resize adjacency list to 1-based indexing

    // Read edges
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w}); // Since the graph is undirected
    }

    vector<int> parent(n + 1, -1); // To store the path
    vector<int> dist = dijkstra(1, parent); // Run Dijkstra from node 1

    if (dist[n] == INF) {
        // No path from 1 to n
        cout << -1 << endl;
        return 0;
    }

    // Reconstruct the shortest path from node n to node 1 using parent[]
    vector<int> path;
    for (int v = n; v != -1; v = parent[v])
        path.push_back(v);
    reverse(path.begin(), path.end()); // Reverse to get 1 → n

    // Print the path
    for (int v : path)
        cout << v << " ";
    cout << endl;

    return 0;
}
