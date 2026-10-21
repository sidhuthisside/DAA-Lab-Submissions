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

    int color[6];
    fill(color, color + n, -1);

    color[0] = 0;

    for (int u = 1; u < n; u++) {
        bool used[6] = {false};

        for (int v : graph[u]) {
            if (color[v] != -1)
                used[color[v]] = true;
        }

        for (int c = 0; c < n; c++) {
            if (!used[c]) {
                color[u] = c;
                break;
            }
        }
    }

    int slots = 0;
    for (int i = 0; i < n; i++)
        slots = max(slots, color[i] + 1);

    cout << "UNIVERSITY EXAM TIMETABLE\n\n";

    for (int i = 0; i < n; i++)
        cout << course[i] << " -> Slot " << color[i] + 1 << "\n";

    cout << "\nMinimum slots used by this greedy ordering: " << slots << "\n";

    return 0;
}
