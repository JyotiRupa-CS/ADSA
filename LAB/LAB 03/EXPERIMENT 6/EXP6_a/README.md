# 🧮 Prim’s Algorithm in C

![Language](https://img.shields.io/badge/Language-C-blue.svg)
![Algorithm](https://img.shields.io/badge/Algorithm-Prim's%20MST-green.svg)
![Complexity](https://img.shields.io/badge/Time%20Complexity-O(V²)-yellow.svg)
![Status](https://img.shields.io/badge/Status-Completed-success.svg)

This project implements **Prim’s Minimum Spanning Tree (MST)** algorithm in **C** using an adjacency matrix.  
It finds the **minimum total weight** needed to connect all vertices of a **weighted, undirected graph** without forming cycles.

---

## 🌟 Features
✅ Step-by-step implementation of **Prim’s Algorithm**  
✅ Works for **undirected weighted graphs**  
✅ Displays **edges** included in the MST  
✅ Calculates and shows the **total MST cost**

---

## ⚙️ How It Works
1. The program takes:
   - Number of vertices (`n`)
   - Number of edges (`e`)
   - Each edge as: `vertex1 vertex2 weight`
2. Initializes an adjacency matrix with `INT_MAX` to represent missing edges.
3. Selects the vertex with the **smallest edge weight** not yet included in the MST.
4. Repeats until all vertices are connected.
5. Displays the MST edges and total cost.

---


---

## 🧰 Requirements
- C compiler (e.g., `gcc`)
- Any IDE or terminal supporting C (VS Code, Code::Blocks, Dev C++, etc.)

---

## 🚀 Compilation & Execution
```bash
# Compile the program
EXP6_a.exe

