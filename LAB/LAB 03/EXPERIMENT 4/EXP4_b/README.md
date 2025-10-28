# 🌲 B-Tree Implementation in C

This project implements a **B-Tree (Balanced Search Tree)** in **C language**.  
It supports key insertion, deletion, and traversal operations, maintaining balance and sorted order efficiently.

---

## 🚀 Features

- ✅ Dynamic B-Tree node creation  
- ✅ Insertion with automatic node splitting  
- ✅ Deletion with key replacement and balancing  
- ✅ Inorder traversal (sorted output)  
- ✅ Handles both leaf and non-leaf deletions  
- ✅ Order `t = 2` (max 3 keys per node)

---

## 🧠 What is a B-Tree?

A **B-Tree** is a **self-balancing search tree** that maintains sorted data and allows:
- Efficient **search**, **insertion**, and **deletion** in **O(log n)** time.
- All **leaves appear at the same level**, keeping the tree balanced.
- Nodes can contain **multiple keys** and **multiple children**.

It is widely used in **databases** and **file systems** where large blocks of data are read/written from disk.

---

## ⚙️ Key Properties of a B-Tree

| Property | Description |
|-----------|--------------|
| Order (t) | Minimum degree of the tree (here, t = 2) |
| Max Keys per Node | `2t - 1` = 3 |
| Min Keys per Node | `t - 1` = 1 |
| Children per Node | Between `t` and `2t` |
| Balance | All leaves appear on the same level |

---

## 🧩 Algorithm Summary

### 🔹 Insertion
1. Start from the root.
2. If the node is full (max keys), **split** it into two.
3. Promote the middle key to the parent.
4. Recursively insert the new key into the correct child.

### 🔹 Deletion
1. Locate the key.
2. If the key is in a **leaf**, remove it directly.
3. If it’s in an **internal node**, replace it with its **predecessor** (largest key in left subtree).
4. Recursively delete the key and rebalance if needed.

### 🔹 Traversal
Performs an **inorder traversal**, printing keys in sorted order.

---

## 🧮 Important Formulas

### Node Structure:
\[
\text{Each Node: } [k_1, k_2, ..., k_m] \text{ with children } [c_0, c_1, ..., c_m]
\]

### Split Condition:
\[
\text{If } m = 2t - 1 \Rightarrow \text{Node Split Occurs}
\]

### Height of B-Tree:
\[
h \le \log_t \left(\frac{n+1}{2}\right)
\]

---

## 🧪 Example Execution

### Input:

Enter number of elements to insert: 7
Enter 7 elements: 10 20 5 6 12 30 7

B-Tree inorder traversal after insertion: 5 6 7 10 12 20 30

Enter number of elements to delete: 2
Enter 2 elements to delete: 6 20


### Output:

B-Tree inorder traversal after deletion: 5 7 10 12 30


---

## 🖥️ Compilation & Execution

### 🔧 Compile
```bash
EXP4_b.exe
