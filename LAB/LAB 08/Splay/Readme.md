# Splay Tree in C

This project provides an implementation of a Splay Tree in C.  
A Splay Tree is a self-adjusting binary search tree that moves the most recently
accessed node to the root using rotations. This provides good amortized 
performance for search-heavy workloads.

This implementation supports the essential operations and is suitable for
academic assignments and demonstrations.

---

## Features Implemented

### ✔ Splaying
Moves a node to the root using:
- Zig rotation
- Zig-Zig rotation
- Zig-Zag rotation

### ✔ Insert
Inserts a new key into the tree and splays it to the root.

### ✔ Search
Searches for a key and splays the accessed node to the root.

### ✔ Preorder Traversal
Used to display structure after various operations.

---

## Data Structure Overview

A Splay Tree maintains standard BST (Binary Search Tree) ordering, but after 
every operation (insert or search), rotations are applied so that the accessed 
node becomes the root. This ensures:

- Amortized **O(log n)** time per operation  
- Recently accessed elements are quicker to access again  
- No need to store extra balance information (unlike AVL/Red-Black Trees)

Each node stores:
- Key  
- Left child pointer  
- Right child pointer  

---

## Files Included

- `splay_user.c`  
  C program implementing splay trees with insert, search, and preorder traversal.

- `README.md`  
  Documentation file for understanding the structure and usage.

---

## Compilation

To compile the program:

```bash
Splay.exe
