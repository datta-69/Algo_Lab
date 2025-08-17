#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, W;
    cout << "Enter number of items: ";
    cin >> n;
    cout << "Enter maximum capacity of knapsack: ";
    cin >> W;

    vector<int> weight(n), value(n);
    cout << "Enter weights of items:\n";
    for (int i = 0; i < n; i++) cin >> weight[i];
    cout << "Enter values of items:\n";
    for (int i = 0; i < n; i++) cin >> value[i];

    // DP table
    vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));

    // Bottom-up DP filling
    for (int i = 1; i <= n; i++) {
        for (int w = 0; w <= W; w++) {
            if (weight[i - 1] <= w) {
                dp[i][w] = max(dp[i - 1][w],
                               value[i - 1] + dp[i - 1][w - weight[i - 1]]);
            } else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    int maxValue = dp[n][W];
    cout << "Maximum value that can be obtained: " << maxValue << endl;

    // Reconstruct chosen items
    int w = W, totalWeight = 0;
    vector<int> chosen;
    for (int i = n; i > 0; i--) {
        if (dp[i][w] != dp[i - 1][w]) {
            chosen.push_back(i - 1); // item index
            totalWeight += weight[i - 1];
            w -= weight[i - 1];
        }
    }

    cout << "Total weight used: " << totalWeight << endl;

    cout << "Items taken (0-based index): ";
    for (int i = chosen.size() - 1; i >= 0; i--) {
        cout << chosen[i] << " ";
    }
    cout << endl;

    cout << "Items taken (weight, value): ";
    for (int i = chosen.size() - 1; i >= 0; i--) {
        int idx = chosen[i];
        cout << "(" << weight[idx] << ", " << value[idx] << ") ";
    }
    cout << endl;

    return 0;
}