# 🛰️ Dijkstra’s Shortest Path Algorithm in C

## 📘 Project Overview
This project implements **Dijkstra’s Algorithm** using **C language** to find the **shortest path** from a source node to all other nodes in a weighted graph.  
The algorithm uses an **adjacency matrix** representation and prints the shortest distance from the source to each node.

---

## ⚙️ Features
- ✅ Implements Dijkstra’s algorithm efficiently  
- ✅ Supports up to **100 nodes**  
- ✅ Handles **weighted undirected graphs**  
- ✅ Displays unreachable nodes as `INF`  
- ✅ Simple command-line interface  

---

## 🧩 Algorithm Workflow
1. Initialize distances to all vertices as infinity (`INF`).
2. Set the distance to the **source node** as `0`.
3. Repeatedly pick the **unvisited node** with the smallest distance.
4. Update distances of all its adjacent nodes.
5. Mark the node as visited and repeat until all nodes are processed.

---


---

## 🧪 Example Execution

### Input:
Enter number of nodes: 5
Enter adjacency matrix:
0 10 0 30 100
10 0 50 0 0
0 50 0 20 10
30 0 20 0 60
100 0 10 60 0
Enter source node index: 0



### Output:


---

## 🧾 Input Format
- The first input is the **number of nodes (n)**.
- Then provide the **adjacency matrix** of size `n x n`.
- Each value `graph[i][j]` represents the weight of the edge between node `i` and node `j`.
- Use `0` for **no edge**.

**Example Matrix:**
0 4 0 0
4 0 8 0
0 8 0 2
0 0 2 0


---

## ⚙️ Compilation & Execution

### 🧠 Step 1: Compile
```bash
EXP5_B.exe


