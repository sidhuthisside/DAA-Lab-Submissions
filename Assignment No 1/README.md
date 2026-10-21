# Assignment No. 1 — Design and Analysis of Algorithms

## Sorting a Real-World Dataset Using Merge Sort

---

## 📌 Objective

Implement the **Merge Sort** algorithm in C++ to sort a real-world dataset of academic faculty salaries in **ascending order of annual salary**, and compute basic statistics (minimum, maximum, average).

---

## 📂 Files in This Folder

| File | Description |
|------|-------------|
| `assignment1.cpp` | C++ source code implementing Merge Sort |
| `Salaries.csv` | Dataset — Academic faculty salaries |
| `README.md` | This documentation file |

---

## 📊 Dataset — `Salaries.csv`

- **Source:** [GitHub — vkrit/python-for-data-science](https://github.com/vkrit/python-for-data-science/blob/master/Salaries.csv)
- **Domain:** Academic faculty compensation (US universities)
- **Records:** 50 rows

### Column Description

| Column | Type | Description |
|--------|------|-------------|
| `rank` | String | Faculty rank (`Prof`, `AssocProf`, `AsstProf`) |
| `discipline` | String | Department type (`A` = theoretical, `B` = applied) |
| `phd` | Integer | Years since PhD |
| `service` | Integer | Years of service at institution |
| `sex` | String | Gender (`Male` / `Female`) |
| `salary` | Integer | Annual salary in USD |

---

## 🧠 Algorithm — Merge Sort

### Concept

Merge Sort is a **Divide and Conquer** algorithm that:
1. **Divides** the array into two halves recursively until each sub-array has one element.
2. **Conquers** by merging two sorted halves into one sorted array.

### Pseudocode

```
MERGE_SORT(array, left, right):
    if left >= right:
        return
    mid = left + (right - left) / 2
    MERGE_SORT(array, left, mid)
    MERGE_SORT(array, mid+1, right)
    MERGE(array, left, mid, right)

MERGE(array, left, mid, right):
    create temp[]
    i = left, j = mid+1
    while i <= mid AND j <= right:
        if array[i].salary <= array[j].salary:
            temp.append(array[i++])
        else:
            temp.append(array[j++])
    copy remaining elements of left half
    copy remaining elements of right half
    copy temp[] back to array[left..right]
```

### Complexity Analysis

| Case | Time Complexity | Reason |
|------|----------------|--------|
| Best Case | **O(n log n)** | Always divides into equal halves |
| Average Case | **O(n log n)** | Same divide-and-conquer structure |
| Worst Case | **O(n log n)** | No worst case for merge sort |

| Space | Complexity |
|-------|-----------|
| Auxiliary | **O(n)** | Temporary array used during merge |
| Recursive Stack | **O(log n)** | Depth of recursion tree |

### Recurrence Relation

```
T(n) = 2T(n/2) + O(n)
```

Solving using the **Master Theorem** (Case 2):
> a = 2, b = 2, f(n) = n → n^(log₂2) = n¹ = n  
> Since f(n) = Θ(n^log_b a) → **T(n) = O(n log n)**

---

## 🔧 How to Compile and Run

### Prerequisites
- A C++ compiler such as **g++** (MinGW for Windows, GCC for Linux/Mac)

### Steps

```bash
# Step 1 — Navigate to the assignment folder
cd "Assignment No 1"

# Step 2 — Compile
g++ -o assignment1 assignment1.cpp

# Step 3 — Run
./assignment1      # Linux / Mac
assignment1.exe    # Windows
```

> ⚠️ Make sure `Salaries.csv` is in the **same directory** as the compiled executable.

---

## 💻 Sample Output

```
  Records loaded from CSV : 50
  Applying Merge Sort on Salary column...
  Sorting complete!

  ====================================================================
   SORTED FACULTY SALARY RECORDS (Ascending Order of Salary)
  ====================================================================
  No.  Rank        Disc  PhD Yrs  Service  Sex     Salary (USD)
  --------------------------------------------------------------------
  1    AsstProf    A     2        2        Female  $    67644
  2    AsstProf    A     4        4        Female  $    67871
  3    AsstProf    A     2        2        Male    $    68750
  ...
  ====================================================================

  SALARY STATISTICS
  ----------------------------------------
  Total Records  : 50
  Minimum Salary : $57800
  Maximum Salary : $186960
  Average Salary : $107213.60
  ----------------------------------------
```

---

## 📈 Why Merge Sort?

| Algorithm | Best | Average | Worst | Stable? |
|-----------|------|---------|-------|---------|
| Bubble Sort | O(n) | O(n²) | O(n²) | ✅ Yes |
| Selection Sort | O(n²) | O(n²) | O(n²) | ❌ No |
| Insertion Sort | O(n) | O(n²) | O(n²) | ✅ Yes |
| **Merge Sort** | **O(n log n)** | **O(n log n)** | **O(n log n)** | ✅ **Yes** |
| Quick Sort | O(n log n) | O(n log n) | O(n²) | ❌ No |

Merge Sort is chosen because:
- It guarantees **O(n log n)** in all cases (no worst-case degradation)
- It is **stable** — equal salary records maintain their relative order
- It is well-suited for **external sorting** of large datasets

---

## 🔍 Key Observations from Output

1. **Assistant Professors** typically earn the **lowest salaries**
2. **Full Professors** dominate the **higher salary brackets**
3. **Discipline B** (Applied) tends to have slightly **higher compensation** than Discipline A (Theoretical)
4. The salary range spans from **~$57,800** to **~$186,960**

---

## 📚 References

1. Cormen, T. H., Leiserson, C. E., Rivest, R. L., & Stein, C. (2009). *Introduction to Algorithms* (3rd ed.). MIT Press.
2. Dataset Source: [Salaries.csv — vkrit/python-for-data-science](https://github.com/vkrit/python-for-data-science/blob/master/Salaries.csv)
3. Knuth, D. E. (1998). *The Art of Computer Programming, Vol. 3: Sorting and Searching* (2nd ed.). Addison-Wesley.

---

*Assignment submitted for DAA Lab | Academic Year 2025–2026*
