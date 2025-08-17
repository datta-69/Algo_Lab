#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int n;  // number of cities
vector<vector<int>> dist;  // distance matrix
vector<bool> visited;
int ans = INT_MAX;
vector<int> bestPath, currPath;

void tsp(int currPos, int count, int costSoFar) {
    // Base case: all cities visited
    if (count == n && dist[currPos][0] > 0) {
        int totalCost = costSoFar + dist[currPos][0];
        if (totalCost < ans) {
            ans = totalCost;
            bestPath = currPath;
            bestPath.push_back(0); // return to starting city
        }
        return;
    }

    // Try next cities
    for (int next = 0; next < n; next++) {
        if (!visited[next] && dist[currPos][next] > 0) {
            visited[next] = true;
            currPath.push_back(next);

            tsp(next, count + 1, costSoFar + dist[currPos][next]);

            visited[next] = false;  // backtrack
            currPath.pop_back();
        }
    }
}

int main() {
    cout << "Enter number of cities: ";
    cin >> n;

    dist.assign(n, vector<int>(n));
    cout << "Enter distance matrix:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> dist[i][j];
        }
    }

    visited.assign(n, false);
    visited[0] = true;  // start at city 0
    currPath.push_back(0);

    tsp(0, 1, 0);

    cout << "Minimum cost of TSP tour = " << ans << endl;
    cout << "Tour path: ";
    for (int city : bestPath) {
        cout << city << " ";
    }
    cout << endl;

    return 0;
}