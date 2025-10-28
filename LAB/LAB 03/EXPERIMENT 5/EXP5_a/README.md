# 🧮 SIF File Graph Reader in C

## 📘 Overview
This project implements a **graph construction and visualization system** in C using data from a **SIF (Simple Interaction Format)** file.  
It reads nodes and their relationships, stores them in an **adjacency matrix**, and displays the entire graph structure.

---

## 🧠 What is a SIF File?
A **SIF (Simple Interaction Format)** file represents pairwise relationships between nodes — often used in **bioinformatics**, **social network analysis**, and **graph data visualization**.

Each line follows the structure:

Source Interaction Target


### Example:
A pp B
B pp C
C pp D


Here:
- **A**, **B**, **C**, and **D** are *nodes*.
- **pp** indicates a *connection* (interaction) between them.
- Each pair forms an *undirected edge* in the graph.

---

## ⚙️ Features
✅ Reads SIF files and automatically detects nodes  
✅ Builds and displays the **adjacency matrix**  
✅ Supports **undirected graphs**  
✅ Error handling for missing files  
✅ Simple, clear, and extendable C code  

---

## 🧩 Algorithm Steps

### Step 1: Initialize Graph
The program creates an empty adjacency matrix:
\[
A[i][j] = 0 \quad \forall i, j
\]

### Step 2: Parse SIF File
For each line in the SIF file:
\[
(u, \text{edge}, v)
\]

Add nodes if they don’t already exist.

### Step 3: Build Edges
\[
A[i][j] = 1, \quad A[j][i] = 1
\]
(since it’s an **undirected** graph)

### Step 4: Display Result
Print the list of nodes and the adjacency matrix.

---

## 🧮 Mathematical Representation
If we define a graph \( G = (V, E) \):

\[
V = \{v_1, v_2, ..., v_n\}
\]

Then, the adjacency matrix \( A \) is defined as:
\[
A[i][j] =
\begin{cases}
1, & \text{if } (v_i, v_j) \in E \\
0, & \text{otherwise}
\end{cases}
\]

---


---

## ⚙️ How to Compile and Run

### 🖥️ Step 1: Compile the program
```bash
EXP5_a.exe

