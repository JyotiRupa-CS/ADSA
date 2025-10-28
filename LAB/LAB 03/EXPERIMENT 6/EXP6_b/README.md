# 🧮 Prim's Algorithm in C

This project implements **Prim’s Algorithm** to find the **Minimum Spanning Tree (MST)** of a connected, undirected, weighted graph.  
The MST connects all vertices with the minimum possible total edge weight and without any cycles.

---

## 📘 Features
- Simple, well-structured **C implementation**
- Works for any **connected, undirected graph**
- Allows **custom input** of vertices, edges, and weights
- Displays:
  - All edges included in the MST
  - Total weight of the MST

---

## 🧠 Algorithm Overview

Prim’s Algorithm starts with one vertex and repeatedly adds the smallest edge that connects a new vertex to the growing MST.

### Steps:
1. Initialize all vertex keys to infinity except the starting vertex (key = 0).
2. Pick the vertex with the minimum key that’s not yet in the MST.
3. Include it in the MST set.
4. Update keys for all adjacent vertices if the connecting edge has a smaller weight.
5. Repeat until all vertices are included.

---

## 🧩 Program Structure

| Function | Description |
|-----------|-------------|
| `minKey()` | Finds the vertex with the smallest key value not yet included in the MST |
| `primMST()` | Executes Prim’s algorithm and prints the MST edges and total weight |
| `main()` | Handles user input and constructs the adjacency matrix |

---

## 💻 How to Run

### 1️⃣ Save the code as `prims.c`
```bash
EXP6_b.exe
