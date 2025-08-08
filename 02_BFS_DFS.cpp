#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <unordered_set>
using namespace std;

class Graph {
private:
    int vertices;
    vector<vector<int>> adj_list;

public:
    Graph(int v) : vertices(v), adj_list(v) {}

    void add_edge(int u, int v) {
        adj_list[u].push_back(v);
        adj_list[v].push_back(u);
    }

    vector<int> dfs_traversal(int start) {
        vector<int> traversal_order;
        unordered_set<int> visited;
        stack<int> s;

        s.push(start);

        while (!s.empty()) {
            int node = s.top();
            s.pop();

            if (visited.find(node) == visited.end()) {
                visited.insert(node);
                traversal_order.push_back(node);

                // Push neighbors in reverse to maintain order
                for (auto it = adj_list[node].rbegin(); it != adj_list[node].rend(); ++it) {
                    if (visited.find(*it) == visited.end()) {
                        s.push(*it);
                    }
                }
            }
        }
        return traversal_order;
    }

    vector<int> bfs_traversal(int start) {
        vector<int> traversal_order;
        unordered_set<int> visited;
        queue<int> q;

        q.push(start);
        visited.insert(start);

        while (!q.empty()) {
            int node = q.front();
            q.pop();
            traversal_order.push_back(node);

            for (int neighbor : adj_list[node]) {
                if (visited.find(neighbor) == visited.end()) {
                    visited.insert(neighbor);
                    q.push(neighbor);
                }
            }
        }
        return traversal_order;
    }

    bool dfs_path_exists(int start, int end) {
        if (start == end) return true;
        unordered_set<int> visited;
        stack<int> s;
        s.push(start);

        while (!s.empty()) {
            int node = s.top();
            s.pop();

            if (visited.find(node) == visited.end()) {
                visited.insert(node);
                for (int neighbor : adj_list[node]) {
                    if (neighbor == end) return true;
                    if (visited.find(neighbor) == visited.end()) {
                        s.push(neighbor);
                    }
                }
            }
        }
        return false;
    }

    bool bfs_path_exists(int start, int end) {
        if (start == end) return true;
        unordered_set<int> visited;
        queue<int> q;
        q.push(start);
        visited.insert(start);

        while (!q.empty()) {
            int node = q.front();
            q.pop();

            for (int neighbor : adj_list[node]) {
                if (neighbor == end) return true;
                if (visited.find(neighbor) == visited.end()) {
                    visited.insert(neighbor);
                    q.push(neighbor);
                }
            }
        }
        return false;
    }
};

int main() {
    int vertices, edges, u, v, source, target;

    cout << "Enter number of vertices: ";
    cin >> vertices;
    cout << "Enter number of edges: ";
    cin >> edges;

    Graph graph(vertices);

    cout << "Enter edges:\n";
    for (int i = 0; i < edges; i++) {
        cin >> u >> v;
        graph.add_edge(u, v); // assuming 0-based indexing
    }

    cout << "Enter source node: ";
    cin >> source;
    cout << "Enter target node: ";
    cin >> target;

    vector<int> dfs_order = graph.dfs_traversal(source);
    vector<int> bfs_order = graph.bfs_traversal(source);

    bool dfs_path = graph.dfs_path_exists(source, target);
    bool bfs_path = graph.bfs_path_exists(source, target);

    cout << "\nDFS Traversal: ";
    for (int node : dfs_order) cout << node << " ";

    cout << "\nBFS Traversal: ";
    for (int node : bfs_order) cout << node << " ";

    cout << "\nPath exists from " << source << " to " << target << " (DFS): "
         << (dfs_path ? "Yes" : "No");
    cout << "\nPath exists from " << source << " to " << target << " (BFS): "
         << (bfs_path ? "Yes" : "No") << endl;

    return 0;
}
