# 🧩 Graph Matching in C

## 📘 Overview
This project implements a **graph matching algorithm** in the C programming language.  
It finds pairs of vertices (edges) that form a **maximal matching** — meaning no additional edges can be added without overlapping existing matches.  
The graph input is taken directly from the user through the console.

---

## ⚙️ Features
- Accepts user input for vertices and edges.  
- Supports **undirected graphs**.  
- Displays all matched vertex pairs.  
- Computes the total number of matches found.  
- Simple **greedy-based approach**, ideal for learning and experimentation.

---

## 🧠 Working Principle
1. All vertices are initially marked as **unmatched**.  
2. For each vertex, the program looks for the first available unmatched neighbor.  
3. If such a neighbor exists, the edge between them is added to the matching set.  
4. Both vertices are then marked as matched, ensuring no vertex appears in more than one matched pair.  
5. The process continues until all vertices are processed.

The output is a **set of matched edges** and the **total number of matches** in the given graph.

---

## 📊 Input Format
When running the program, you’ll be prompted to:
1. Enter the number of vertices.  
2. Enter the number of edges.  
3. Provide each edge as a pair of connected vertices `(u, v)`.
   


---

## 📋 Output
The program displays:
- A list of matched vertex pairs.  
- The total number of matches found.


---

## 💻 How to Compile and Run

```bash
# Step 1: Compile the program
gcc graph_matching.c -o graph_matching

# Step 2: Run the executable
Matching.exe
  


