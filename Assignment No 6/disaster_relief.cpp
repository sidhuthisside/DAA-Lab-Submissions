#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n = 5;
    int capacity = 10;

    string items[] = {"Food", "Medicine", "Blankets", "Water", "FirstAid"};
    int weight[] = {3, 2, 5, 4, 1};
    int value[] = {4, 10, 6, 7, 8};

    vector<vector<int>> dp(n + 1, vector<int>(capacity + 1, 0));

    for (int i = 1; i <= n; i++) {
        for (int w = 0; w <= capacity; w++) {
            if (weight[i - 1] <= w) {
                dp[i][w] = max(
                    value[i - 1] + dp[i - 1][w - weight[i - 1]],
                    dp[i - 1][w]
                );
            } else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    cout << "DISASTER RELIEF - 0/1 KNAPSACK\n";
    cout << "Truck capacity: " << capacity << " kg\n";
    cout << "Maximum utility: " << dp[n][capacity] << "\n";

    cout << "Selected items:\n";
    int w = capacity;
    int totalWeight = 0;

    for (int i = n; i > 0; i--) {
        if (dp[i][w] != dp[i - 1][w]) {
            cout << items[i - 1] << " ("
                 << weight[i - 1] << " kg, utility "
                 << value[i - 1] << ")\n";
            totalWeight += weight[i - 1];
            w -= weight[i - 1];
        }
    }

    cout << "Total weight: " << totalWeight << " kg\n";
    return 0;
}
