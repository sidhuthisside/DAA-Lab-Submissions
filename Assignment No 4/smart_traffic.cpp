#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int main() {
    int n = 6;
    string name[] = {"S", "A", "B", "C", "D", "H"};

    vector<pair<int, int>> graph[6];

    auto addRoad = [&](int u, int v, int w) {
        graph[u].push_back({v, w});
        graph[v].push_back({u, w});
    };

    addRoad(0, 1, 4);
    addRoad(0, 2, 2);
    addRoad(1, 2, 1);
    addRoad(1, 3, 5);
    addRoad(2, 3, 8);
    addRoad(2, 4, 10);
    addRoad(3, 4, 2);
    addRoad(3, 5, 3);
    addRoad(4, 5, 1);

    auto updateRoad = [&](int u, int v, int w) {
        for (auto &e : graph[u])
            if (e.first == v) e.second = w;

        for (auto &e : graph[v])
            if (e.first == u) e.second = w;
    };

    auto dijkstra = [&](int source, vector<int> &dist, vector<int> &parent) {
        dist.assign(n, 1000000);
        parent.assign(n, -1);

        priority_queue<pair<int, int>,
                       vector<pair<int, int>>,
                       greater<pair<int, int>>> pq;

        dist[source] = 0;
        pq.push({0, source});

        while (!pq.empty()) {
            int time = pq.top().first;
            int u = pq.top().second;
            pq.pop();

            if (time != dist[u]) continue;

            for (auto e : graph[u]) {
                int v = e.first;
                int w = e.second;

                if (dist[u] + w < dist[v]) {
                    dist[v] = dist[u] + w;
                    parent[v] = u;
                    pq.push({dist[v], v});
                }
            }
        }
    };

    vector<int> dist, parent;

    cout << "Before traffic update:\n";
    dijkstra(0, dist, parent);

    for (int i = 0; i < n; i++)
        cout << "S to " << name[i] << " = " << dist[i] << " minutes\n";

    int hospital = (dist[4] <= dist[5]) ? 4 : 5;
    vector<int> path;

    for (int v = hospital; v != -1; v = parent[v])
        path.push_back(v);

    reverse(path.begin(), path.end());

    cout << "Nearest hospital: " << name[hospital]
         << " (" << dist[hospital] << " minutes)\n";
    cout << "Route: ";
    for (int i = 0; i < path.size(); i++) {
        if (i > 0) cout << " -> ";
        cout << name[path[i]];
    }
    cout << "\n\n";

    cout << "Traffic update: S-B changes from 2 to 6 minutes.\n";
    updateRoad(0, 2, 6);

    cout << "\nAfter traffic update:\n";
    dijkstra(0, dist, parent);

    for (int i = 0; i < n; i++)
        cout << "S to " << name[i] << " = " << dist[i] << " minutes\n";

    hospital = (dist[4] <= dist[5]) ? 4 : 5;
    path.clear();

    for (int v = hospital; v != -1; v = parent[v])
        path.push_back(v);

    reverse(path.begin(), path.end());

    cout << "Nearest hospital: " << name[hospital]
         << " (" << dist[hospital] << " minutes)\n";
    cout << "Updated route: ";
    for (int i = 0; i < path.size(); i++) {
        if (i > 0) cout << " -> ";
        cout << name[path[i]];
    }
    cout << "\n";

    return 0;
}
