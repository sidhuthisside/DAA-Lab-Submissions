# Assignment No. 4 — Graph Algorithms

This folder contains two graph-algorithm demonstrations.

## Programs

| Source file | Description | Saved output |
|---|---|---|
| `exam_timetable.cpp` | Applies the Welsh–Powell greedy graph-coloring algorithm to assign exam time slots. | `exam_timetable_output.txt` |
| `smart_traffic.cpp` | Uses Dijkstra's algorithm to find shortest travel times and a nearest hospital, then recalculates after a traffic update. | `smart_traffic_output.txt` |

## Exam Timetabling

Courses are vertices, and an edge indicates that two exams cannot be held in the same slot. The program orders courses by descending degree, then greedily assigns each course the lowest available color (slot). It reports three slots for the sample graph.

Compile and run from this folder:

```bash
g++ -o exam_timetable.exe exam_timetable.cpp
exam_timetable.exe
```

## Smart Traffic Routing

The road network is a weighted, undirected graph. The program calculates shortest travel times from `S`, selects the nearer of hospitals `D` and `H`, then updates the `S-B` travel time and recalculates the routes.

Compile and run from this folder:

```bash
g++ -o smart_traffic.exe smart_traffic.cpp
smart_traffic.exe
```

*Assignment submitted for DAA Lab | Academic Year 2025–2026*
