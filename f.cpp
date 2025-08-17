#include <bits/stdc++.h>
using namespace std;

#define INF 999999 // A large value to represent infinity
#define V 15       // Since we have 14 nodes (1..14)

// Function to print the distance matrix
void printSolution(int dist[V][V]) {
    cout << "All Pairs Shortest Path Matrix (Floyd-Warshall):\n";
    for (int i = 1; i < V; i++) {
        for (int j = 1; j < V; j++) {
            if (dist[i][j] == INF)
                cout << "INF" << "\t";
            else
                cout << dist[i][j] << "\t";
        }
        cout << endl;
    }
}

void floydWarshall(int graph[V][V]) {
    int dist[V][V];

    // Step 1: Initialize solution matrix as graph matrix
    for (int i = 0; i < V; i++)
        for (int j = 0; j < V; j++)
            dist[i][j] = graph[i][j];

    // Step 2: Update distances
    for (int k = 1; k < V; k++) {
        for (int i = 1; i < V; i++) {
            for (int j = 1; j < V; j++) {
                if (dist[i][k] + dist[k][j] < dist[i][j])
                    dist[i][j] = dist[i][k] + dist[k][j];
            }
        }
    }

    // Step 3: Print the result
    printSolution(dist);
}

int main() {
    // Initialize graph with INF
    int graph[V][V];
    for (int i = 0; i < V; i++)
        for (int j = 0; j < V; j++)
            graph[i][j] = (i == j) ? 0 : INF;

    // Add edges from your image (undirected graph)
    graph[1][2] = graph[2][1] = 3;
    graph[2][3] = graph[3][2] = 2;
    graph[3][4] = graph[4][3] = 1;
    graph[4][6] = graph[6][4] = 4;
    graph[6][5] = graph[5][6] = 2;
    graph[6][7] = graph[7][6] = 4;
    graph[7][9] = graph[9][7] = 2;
    graph[9][10] = graph[10][9] = 1;
    graph[10][4] = graph[4][10] = 3;
    graph[10][12] = graph[12][10] = 2;
    graph[12][13] = graph[13][12] = 3;
    graph[13][1] = graph[1][13] = 6;
    graph[13][14] = graph[14][13] = 2;
    graph[12][11] = graph[11][12] = 2;
    graph[11][9] = graph[9][11] = 5;
    graph[9][8] = graph[8][9] = 12;

    // Run Floyd-Warshall
    floydWarshall(graph);

    return 0;
}
