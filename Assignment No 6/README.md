# Assignment No. 6 — Disaster Relief Knapsack

## Objective

Choose disaster-relief supplies to maximize total utility without exceeding the truck's weight capacity.

## Files

| File | Description |
|---|---|
| `disaster_relief.cpp` | C++ implementation of the 0/1 Knapsack dynamic programming algorithm. |
| `disaster_relief_output.txt` | Saved sample output, including selected supplies and their total weight. |

## Algorithm

Each supply is either selected whole or not selected. The program builds a dynamic programming table indexed by the number of considered items and the capacity currently available. For each item, it compares the utility of including it with the utility of leaving it out, then traces the table backward to report the selected supplies.

For the sample capacity of `10 kg`, the maximum utility is `29`; the selected supplies total `10 kg`.

## Compile and Run

Run these commands from this folder:

```bash
g++ -o disaster_relief.exe disaster_relief.cpp
disaster_relief.exe
```

*Assignment submitted for DAA Lab | Academic Year 2025–2026*
