# Assignment No. 7 — Exam Timetabling with Greedy Graph Coloring

## Objective

Assign exam slots so that courses connected by a conflict edge are not scheduled in the same slot.

## Files

| File | Description |
|---|---|
| `exam_timetable graph coloring.cpp` | C++ implementation of sequential greedy graph coloring. |
| `exam_timetable_output.txt` | Saved output showing the course-to-slot assignments. |

## Algorithm

Courses are vertices, and an edge represents a pair of exams that conflict. The program visits courses in their listed order and assigns each the smallest-numbered slot not already used by a colored neighbor. This is a greedy heuristic; the number of slots depends on the chosen vertex ordering and is not guaranteed to be globally minimal.

For the sample graph, the program uses three slots.

## Compile and Run

Run these commands from this folder:

```bash
g++ -o exam_timetable.exe "exam_timetable graph coloring.cpp"
exam_timetable.exe
```

*Assignment submitted for DAA Lab | Academic Year 2025–2026*
