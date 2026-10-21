#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    int n = 6;
    string name[] = {"Warehouse", "A", "B", "C", "D", "Customer"};
    int stage[] = {0, 1, 1, 2, 2, 3};

    vector<pair<int, int>> graph[6];

    auto addRoad = [&](int u, int v, int cost) {
        graph[u].push_back({v, cost});
    };

    addRoad(0, 1, 4);
    addRoad(0, 2, 2);
    addRoad(1, 3, 3);
    addRoad(1, 4, 6);
    addRoad(2, 3, 5);
    addRoad(2, 4, 2);
    addRoad(3, 5, 4);
    addRoad(4, 5, 3);

    auto findRoute = [&]() {
        vector<int> dist(n, 1000000), parent(n, -1);
        dist[0] = 0;

        for (int s = 0; s < 3; s++) {
            for (int u = 0; u < n; u++) {
                if (stage[u] != s || dist[u] == 1000000)
                    continue;

                for (auto road : graph[u]) {
                    int v = road.first;
                    int cost = road.second;

                    if (dist[u] + cost < dist[v]) {
                        dist[v] = dist[u] + cost;
                        parent[v] = u;
                    }
                }
            }
        }

        cout << "Minimum delivery cost: " << dist[5] << "\n";
        vector<int> path;

        for (int v = 5; v != -1; v = parent[v])
            path.push_back(v);

        reverse(path.begin(), path.end());

        cout << "Best route: ";
        for (int i = 0; i < path.size(); i++) {
            if (i > 0) cout << " -> ";
            cout << name[path[i]];
        }
        cout << "\n";
    };

    cout << "SWIFTCARGO DELIVERY ROUTE\n\n";
    cout << "Delivery request 1:\n";
    findRoute();

    cout << "\nTraffic update: Warehouse to B cost changes from 2 to 7.\n";
    for (auto &road : graph[0]) {
        if (road.first == 2)
            road.second = 7;
    }

    cout << "\nDelivery request 2 after traffic update:\n";
    findRoute();

    return 0;
}
