# 🌳 AVL Tree Implementation in C

This project implements an **AVL Tree** — a self-balancing Binary Search Tree (BST) — in the **C programming language**.  
It supports insertion, deletion, and traversal operations while ensuring that the tree remains height-balanced after every operation.

---

## 🚀 Features

- ✅ Insertion of nodes while maintaining balance  
- ✅ Deletion of nodes with automatic tree rebalancing  
- ✅ Inorder traversal for sorted output  
- ✅ Automatic height calculation for each node  
- ✅ Handles all rotation cases:
  - Left-Left (LL)
  - Right-Right (RR)
  - Left-Right (LR)
  - Right-Left (RL)

---

## 🧠 What is an AVL Tree?

An **AVL Tree** is a type of self-balancing binary search tree.  
It ensures that for every node, the **difference in heights of its left and right subtrees** (called the *balance factor*) is **at most 1**.

### 🔹 Balance Factor Formula:
\[
\text{Balance Factor} = \text{Height(Left Subtree)} - \text{Height(Right Subtree)}
\]

- If the **balance factor** > 1 → Left-heavy  
- If the **balance factor** < -1 → Right-heavy  
- If the **balance factor** ∈ {-1, 0, 1} → Balanced ✅

---

## ⚙️ Rotations in AVL Tree

To restore balance after insertions or deletions, AVL Trees use **rotations**.

| Case | Condition | Rotation Applied |
|------|------------|------------------|
| **Left-Left (LL)** | Insertion in left subtree of left child | Right Rotation |
| **Right-Right (RR)** | Insertion in right subtree of right child | Left Rotation |
| **Left-Right (LR)** | Insertion in right subtree of left child | Left Rotation → Right Rotation |
| **Right-Left (RL)** | Insertion in left subtree of right child | Right Rotation → Left Rotation |

---

## 🧩 Algorithm Summary

### 🔹 Insertion:
1. Insert key as in a regular BST.  
2. Update height of current node.  
3. Compute balance factor.  
4. If unbalanced, perform the required rotation.

### 🔹 Deletion:
1. Delete key as in BST.  
2. Update height of current node.  
3. Compute balance factor.  
4. If unbalanced, perform rotation to rebalance.

### 🔹 Inorder Traversal:
Prints all elements in **sorted ascending order**.

---

## 🧪 Example Execution
### Input:

Enter the number of elements to insert: 7
Enter 7 elements: 10 20 30 40 50 25 5
Inorder traversal after insertion: 5 10 20 25 30 40 50

Enter key to delete: 40
Inorder traversal after deletion: 5 10 20 25 30 50


### Output:

AVL Tree Balanced Successfully ✅


---

## 🖥️ Compilation & Execution

### 🔧 Compile
```bash
EXP4_a.exe

