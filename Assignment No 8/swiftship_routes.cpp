#include <cmath>
#include <iomanip>
#include <iostream>
#include <queue>
#include <string>
#include <vector>
using namespace std;

const int N = 5;
const int START = 0;
const double MAX_TIME = 5.5;
const string cities[N] = {"A", "B", "C", "D", "E"};

const double distanceKm[N][N] = {
    {0, 10, 15, 20, 18},
    {10, 0, 35, 25, 12},
    {15, 35, 0, 30, 10},
    {20, 25, 30, 0, 15},
    {18, 12, 10, 15, 0}
};

const double fuelRate[N][N] = {
    {0, 2.0, 1.8, 2.2, 2.0},
    {2.0, 0, 2.4, 1.9, 2.1},
    {1.8, 2.4, 0, 2.0, 1.7},
    {2.2, 1.9, 2.0, 0, 2.3},
    {2.0, 2.1, 1.7, 2.3, 0}
};

const double travelHours[N][N] = {
    {0, 0.5, 0.75, 1.2, 1.0},
    {0.5, 0, 1.75, 1.25, 0.6},
    {0.75, 1.75, 0, 1.5, 0.5},
    {1.2, 1.25, 1.5, 0, 1.0},
    {1.0, 0.6, 0.5, 1.0, 0}
};

double fuelCost(int from, int to) {
    return distanceKm[from][to] * fuelRate[from][to];
}

struct Node {
    vector<int> route;
    vector<bool> visited;
    double cost;
    double time;
    double distance;
    double bound;
    int order;
};

struct CompareNode {
    bool operator()(const Node& a, const Node& b) const {
        if (a.bound == b.bound)
            return a.order > b.order;
        return a.bound > b.bound;
    }
};

double lowerBound(const Node& node, bool useTime) {
    int current = node.route.back();
    int unvisitedCount = 0;
    double estimate = useTime ? node.time : node.cost;

    for (int city = 0; city < N; city++) {
        if (!node.visited[city])
            unvisitedCount++;
    }

    for (int from = 0; from < N; from++) {
        if (from != current && node.visited[from])
            continue;

        double cheapest = INFINITY;
        for (int to = 0; to < N; to++) {
            if (from == to)
                continue;

            bool allowed = false;
            if (from == current) {
                allowed = unvisitedCount == 0
                    ? to == START
                    : !node.visited[to];
            } else {
                allowed = to == START || !node.visited[to];
            }

            if (!allowed)
                continue;

            double edge = useTime ? travelHours[from][to] : fuelCost(from, to);
            if (edge < cheapest)
                cheapest = edge;
        }

        if (!isfinite(cheapest))
            return INFINITY;
        estimate += cheapest;
    }

    return estimate;
}

int main() {
    priority_queue<Node, vector<Node>, CompareNode> pending;
    vector<int> bestRoute;
    double bestCost = INFINITY;
    double bestTime = 0;
    double bestDistance = 0;
    int insertionOrder = 0;

    Node first;
    first.route = {START};
    first.visited = vector<bool>(N, false);
    first.visited[START] = true;
    first.cost = 0;
    first.time = 0;
    first.distance = 0;
    first.order = insertionOrder++;
    first.bound = lowerBound(first, false);
    pending.push(first);

    while (!pending.empty()) {
        Node current = pending.top();
        pending.pop();

        if (current.bound >= bestCost)
            continue;
        if (lowerBound(current, true) > MAX_TIME)
            continue;

        if (current.route.size() == N) {
            int last = current.route.back();
            double totalTime = current.time + travelHours[last][START];
            double totalCost = current.cost + fuelCost(last, START);
            double totalDistance = current.distance + distanceKm[last][START];

            if (totalTime <= MAX_TIME && totalCost < bestCost) {
                bestCost = totalCost;
                bestTime = totalTime;
                bestDistance = totalDistance;
                bestRoute = current.route;
            }
            continue;
        }

        int last = current.route.back();
        for (int next = 0; next < N; next++) {
            if (current.visited[next])
                continue;

            Node child = current;
            child.route.push_back(next);
            child.visited[next] = true;
            child.cost += fuelCost(last, next);
            child.time += travelHours[last][next];
            child.distance += distanceKm[last][next];
            child.order = insertionOrder++;
            child.bound = lowerBound(child, false);

            if (child.bound >= bestCost)
                continue;
            if (lowerBound(child, true) > MAX_TIME)
                continue;

            pending.push(child);
        }
    }

    if (bestRoute.empty()) {
        cout << "No route meets the delivery time limit.\n";
        return 0;
    }

    cout << fixed << setprecision(2);
    cout << "SWIFTSHIP DELIVERY ROUTE - LEAST-COST BRANCH AND BOUND\n";
    cout << "Cities: " << N << "\n";
    cout << "Maximum delivery time: " << MAX_TIME << " hours\n\n";

    cout << "Optimal route: ";
    for (int city : bestRoute)
        cout << cities[city] << " -> ";
    cout << cities[START] << "\n\n";

    cout << "Route details:\n";
    for (int i = 0; i < N; i++) {
        int from = bestRoute[i];
        int to = (i + 1 < N) ? bestRoute[i + 1] : START;
        cout << cities[from] << " -> " << cities[to]
             << " | Distance: " << distanceKm[from][to] << " km"
             << " | Fuel cost: $" << fuelCost(from, to)
             << " | Time: " << travelHours[from][to] << " hours\n";
    }

    cout << "\nTotal distance: " << bestDistance << " km\n";
    cout << "Total fuel cost: $" << bestCost << "\n";
    cout << "Total delivery time: " << bestTime << " hours\n";
    return 0;
}
