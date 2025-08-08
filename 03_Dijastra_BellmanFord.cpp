#include <bits/stdc++.h>
using namespace std;

struct Edge {
    int u, v;
    int w;
};

void dijkstra(int n, int src, vector<vector<pair<int,int>>> &adj, vector<string> &names) {
    vector<int> dist(n, INT_MAX);
    dist[src] = 0;
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;
    pq.push({0, src});

    while (!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();
        if (d > dist[u]) continue;

        for (auto [v, w] : adj[u]) {
            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }

    cout << "Node\tDistance\tLocation Name\n";
    for (int i = 0; i < n; i++) {
        cout << i << "\t";
        if (dist[i] == INT_MAX) cout << "INF\t\t";
        else cout << dist[i] << "\t\t";
        cout << names[i] << "\n";
    }
}

void bellmanFord(int n, int src, vector<Edge> &edges, vector<string> &names) {
    vector<int> dist(n, INT_MAX);
    dist[src] = 0;

    for (int i = 1; i < n; i++) {
        for (auto &e : edges) {
            if (dist[e.u] != INT_MAX && dist[e.u] + e.w < dist[e.v]) {
                dist[e.v] = dist[e.u] + e.w;
            }
        }
    }

    // Detect negative cycle
    for (auto &e : edges) {
        if (dist[e.u] != INT_MAX && dist[e.u] + e.w < dist[e.v]) {
            cout << "Graph contains a negative weight cycle.\n";
            return;
        }
    }

    cout << "Node\tDistance\tLocation Name\n";
    for (int i = 0; i < n; i++) {
        cout << i << "\t";
        if (dist[i] == INT_MAX) cout << "INF\t\t";
        else cout << dist[i] << "\t\t";
        cout << names[i] << "\n";
    }
}

int main() {
    // Example graph (replace with actual DIU campus data)
    int n = 5; // number of locations
    vector<string> names = {
        "Admission office",
        "AB-4",
        "Medical Center",
        "Food Court",
        "Library"
    };

    vector<vector<pair<int,int>>> adj_non_negative(n);
    vector<Edge> edges;

    // Example edges: u, v, weight
    vector<Edge> allEdges = {
        {0, 1, 3},
        {0, 2, 8},
        {1, 2, 2},
        {1, 3, 5},
        {2, 3, -4}, // negative edge for Bellman-Ford
        {3, 4, 6}
    };

    // Prepare data
    for (auto &e : allEdges) {
        edges.push_back(e);
        if (e.w >= 0) { // only non-negative edges for Dijkstra
            adj_non_negative[e.u].push_back({e.v, e.w});
        }
    }

    cout << "===== Dijkstra (Non-negative edges only) =====\n";
    dijkstra(n, 0, adj_non_negative, names);

    cout << "\n===== Bellman-Ford (With negative edges) =====\n";
    bellmanFord(n, 0, edges, names);

    return 0;
}
