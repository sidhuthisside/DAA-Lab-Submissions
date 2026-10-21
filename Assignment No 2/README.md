# Assignment No. 2 — Design and Analysis of Algorithms

## Sorting a Real-World Dataset Using Quick Sort

---

## Objective

Implement the **Quick Sort** algorithm in C++ to sort a real-world dataset of popular movies in **ascending order of IMDb rating**.

---

## Files in This Folder

| File | Description |
|------|-------------|
| `assignment2.cpp` | C++ source code implementing Quick Sort |
| `movies_real_titles.csv` | Dataset — Top 50 popular movies with ratings |
| `README.md` | This documentation file |

---

## Dataset — `movies_real_titles.csv`

- **Domain:** Popular movies (IMDb-style ratings)
- **Records:** 50 rows

### Column Description

| Column | Type | Description |
|--------|------|-------------|
| `title` | String | Movie title |
| `rating` | Float | IMDb rating (out of 10) |
| `rel_year` | Integer | Year of release |
| `popularity` | Integer | Popularity score (out of 100) |

---

## Algorithm — Quick Sort

### Concept

Quick Sort is a **Divide and Conquer** algorithm that:
1. Picks a **pivot** element (last element in this implementation).
2. **Partitions** the array so all elements less than or equal to pivot go left, and greater go right.
3. **Recursively sorts** the left and right sub-arrays.

### Pseudocode

```
QUICKSORT(array, low, high):
    if low >= high:
        return
    pivot_index = PARTITION(array, low, high)
    QUICKSORT(array, low, pivot_index - 1)
    QUICKSORT(array, pivot_index + 1, high)

PARTITION(array, low, high):
    pivot = array[high].rating
    i = low - 1
    for j = low to high - 1:
        if array[j].rating <= pivot:
            i++
            swap(array[i], array[j])
    swap(array[i+1], array[high])
    return i + 1
```

### Complexity Analysis

| Case | Time Complexity | Condition |
|------|----------------|-----------|
| Best Case | **O(n log n)** | Pivot always divides array into equal halves |
| Average Case | **O(n log n)** | Random pivot selection |
| Worst Case | **O(n²)** | Pivot is always smallest or largest element |

| Space | Complexity |
|-------|-----------|
| Auxiliary | **O(1)** | In-place sorting (no extra array) |
| Recursive Stack | **O(log n)** average, **O(n)** worst |

### Recurrence Relation

```
Best/Average: T(n) = 2T(n/2) + O(n)  →  O(n log n)
Worst Case:   T(n) = T(n-1) + O(n)   →  O(n²)
```

---

## How to Compile and Run

```bash
# Step 1 — Navigate to the assignment folder
cd "Assignment No 2"

# Step 2 — Compile
g++ -o assignment2 assignment2.cpp

# Step 3 — Run
assignment2.exe      # Windows
./assignment2        # Linux / Mac
```

> Make sure `movies_real_titles.csv` is in the **same directory** as the executable.

---

## Comparison: Quick Sort vs Merge Sort

| Feature | Quick Sort | Merge Sort |
|---------|-----------|------------|
| Best Case | O(n log n) | O(n log n) |
| Average Case | O(n log n) | O(n log n) |
| Worst Case | **O(n²)** | O(n log n) |
| Space | **O(1)** in-place | O(n) extra array |
| Stable | No | Yes |
| Preferred for | In-memory sorting | Linked lists, external sort |

---

*Assignment submitted for DAA Lab | Academic Year 2025–2026*
