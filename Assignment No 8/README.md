# Assignment No. 8 — SwiftShip Delivery Routes

## Objective

Find the least-fuel-cost route that starts at City A, visits every city once, returns to City A, and meets the delivery time limit.

## Files

| File | Description |
|---|---|
| `swiftship_routes.cpp` | C++ implementation of least-cost Branch and Bound for the traveling salesperson problem. |
| `swiftship_routes_output.txt` | Saved output for the sample route. |

## Algorithm

The program orders partial routes by their lower-bound fuel cost. It expands the least-cost route first and prunes routes whose lower bound cannot beat the best complete route. It also prunes a partial route when even its optimistic remaining travel time would exceed the deadline. The lower bounds never overestimate the remaining cost or time, so the least-cost feasible tour is guaranteed.

The road cost is calculated as distance multiplied by the road's fuel-cost rate. Travel times are supplied per road to account for differing road conditions. The sample visits five cities and has a 5.5-hour delivery limit.

## Compile and Run

Run these commands from this folder:

```bash
g++ -o swiftship_routes.exe swiftship_routes.cpp
swiftship_routes.exe
```

*Assignment submitted for DAA Lab | Academic Year 2025–2026*
