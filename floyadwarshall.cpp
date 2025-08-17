#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

const int INF = 1e9; // A large number representing infinity
const int V = 14;    // Number of vertices (1 to 14)

// Edges from the image
vector<tuple<int, int, int>> edges = {
    {1, 2, 3},
    {1, 13, 6},
    {2, 3, 2},
    {3, 4, 1},
    {4, 6, 4},
    {5, 6, 2},
    {6, 7, 4},
    {7, 9, 2},
    {8, 9, 12},
    {8, 11, 5},
    {9, 10, 1},
    {10, 4, 3},
    {10, 12, 2},
    {12, 13, 3},
    {12, 14, 2}
};

int main() {
    // Initialize distance matrix
    vector<vector<int>> dist(V + 1, vector<int>(V + 1, INF));

    // Set distance to self = 0
    for (int i = 1; i <= V; ++i) {
        dist[i][i] = 0;
    }

    // Fill initial distances from edges
    for (auto [u, v, w] : edges) {
        dist[u][v] = w;
    }

    // Floyd-Warshall algorithm
    for (int k = 1; k <= V; ++k) {
        for (int i = 1; i <= V; ++i) {
            for (int j = 1; j <= V; ++j) {
                if (dist[i][k] < INF && dist[k][j] < INF)
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }

    // Print shortest distance matrix
    cout << "Shortest distances between every pair of vertices:\n\n";
    for (int i = 1; i <= V; ++i) {
        for (int j = 1; j <= V; ++j) {
            if (dist[i][j] == INF)
                cout << setw(5) << "INF";
            else
                cout << setw(5) << dist[i][j];
        }
        cout << endl;
    }

    return 0;
}
