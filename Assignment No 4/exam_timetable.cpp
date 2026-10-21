#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    int n = 6;
    string course[] = {"Math", "Physics", "Chemistry", "Biology", "English", "Computer"};
    vector<int> graph[6];

    auto addEdge = [&](int u, int v) {
        graph[u].push_back(v);
        graph[v].push_back(u);
    };

    addEdge(0, 1);
    addEdge(0, 2);
    addEdge(1, 2);
    addEdge(1, 3);
    addEdge(2, 4);
    addEdge(3, 4);
    addEdge(3, 5);

    vector<int> degree(n);
    for (int i = 0; i < n; i++)
        degree[i] = graph[i].size();

    vector<int> order(n);
    for (int i = 0; i < n; i++)
        order[i] = i;

    sort(order.begin(), order.end(), [&](int a, int b) {
        return degree[a] > degree[b];
    });

    vector<int> color(n, -1);

    for (int u : order) {
        vector<bool> used(n, false);

        for (int v : graph[u]) {
            if (color[v] != -1)
                used[color[v]] = true;
        }

        int c = 0;
        while (used[c])
            c++;

        color[u] = c;
    }

    int slots = 0;
    for (int i = 0; i < n; i++)
        slots = max(slots, color[i] + 1);

    cout << "UNIVERSITY EXAM TIMETABLE\n\n";
    for (int i = 0; i < n; i++)
        cout << course[i] << " -> Slot " << color[i] + 1 << "\n";

    cout << "\nSlots used by Welsh-Powell: " << slots << "\n";
    cout << "Room allocation: assign one suitable room to each exam in its slot.\n";

    return 0;
}
