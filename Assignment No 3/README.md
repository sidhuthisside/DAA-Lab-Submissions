# Assignment No. 3 — Design and Analysis of Algorithms

## Fractional Knapsack Problem using Greedy Algorithm

---

## Objective

Implement the **Fractional Knapsack** problem using a **Greedy Algorithm** in C++. The goal is to maximize profit by selecting items (or fractions of items) that fit within the knapsack capacity, sorted by their **profit-to-weight ratio**.

---

## Files in This Folder

| File | Description |
|------|-------------|
| `assignment3.cpp` | C++ source code — Fractional Knapsack |
| `README.md` | This documentation file |

---

## Problem Statement

Given `n` items each with a **weight** and **profit**, and a knapsack with a fixed **capacity**:
- You can take a **fraction** of any item (unlike 0/1 Knapsack).
- Maximize the **total profit** without exceeding the capacity.

---

## Algorithm — Greedy Approach

### Steps

1. Compute **profit/weight ratio** for each item.
2. **Sort** items in descending order of ratio.
3. **Greedily pick** items one by one:
   - If full item fits → take it completely (fraction = 1.0)
   - If it doesn't fit → take only the fraction that fits
4. Stop when knapsack is full.

### Pseudocode

```
for each item:
    ratio = profit / weight

sort items by ratio (descending)

remaining = capacity
totalProfit = 0

for each item in sorted order:
    if item.weight <= remaining:
        take full item
        remaining -= item.weight
        totalProfit += item.profit
    else:
        fraction = remaining / item.weight
        totalProfit += profit * fraction
        remaining = 0
        break
```

---

## Complexity Analysis

| Step | Time Complexity |
|------|----------------|
| Compute ratios | O(n) |
| Sort by ratio (Bubble Sort) | O(n²) |
| Fill knapsack | O(n) |
| **Total** | **O(n²)** |

> Using an efficient sort like Quick Sort or Merge Sort would reduce total complexity to **O(n log n)**.

---

## Sample Run

```
Enter number of items: 4
Enter knapsack capacity: 50

Item 1 - Weight: 10
Item 1 - Profit: 60
Item 2 - Weight: 20
Item 2 - Profit: 100
Item 3 - Weight: 30
Item 3 - Profit: 120
Item 4 - Weight: 40
Item 4 - Profit: 160

Items sorted by Profit/Weight Ratio:
--------------------------------------------------
Item    Weight      Profit      Ratio
--------------------------------------------------
1       10.00       60.00       6.00
2       20.00       100.00      5.00
3       30.00       120.00      4.00
4       40.00       160.00      4.00

Filling Knapsack:
-------------------------------------------------------
Item    Fraction    Weight Taken    Profit Taken
-------------------------------------------------------
1       1.00        10.00           60.00
2       1.00        20.00           100.00
3       0.67        20.00           80.00
-------------------------------------------------------
Knapsack Capacity : 50
Total Weight Used : 50
Maximum Profit    : 240.00
-------------------------------------------------------
```

---

## How to Compile and Run

```bash
# Compile
g++ -o assignment3 assignment3.cpp

# Run
assignment3.exe     # Windows
./assignment3       # Linux / Mac
```

---

## Why Greedy Works Here

The **Greedy approach is optimal** for the Fractional Knapsack because:
- Items can be split, so taking the highest ratio item first always leads to maximum profit.
- This is **NOT** optimal for 0/1 Knapsack (where Dynamic Programming is needed).

---

*Assignment submitted for DAA Lab | Academic Year 2025–2026*
