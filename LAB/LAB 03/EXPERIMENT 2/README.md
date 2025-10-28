# 🌳 Binary Search Tree (BST) Implementation in C

## 📘 Overview
This project implements a **Binary Search Tree (BST)** in **C language** with full support for:
- Node creation and insertion  
- Node deletion  
- Inorder, Preorder, and Postorder traversals  
- Displaying the tree structure visually  
- Interactive menu-driven interface for performing operations dynamically

---

## 🧠 Algorithm Summary

### 🟢 Insertion
- If the tree is empty, the first node becomes the root.
- If the value to insert is smaller than the root, it goes to the left subtree.
- If larger, it goes to the right subtree.
- Duplicates are **not inserted**.

### 🔴 Deletion
1. If the node to delete has:
   - **No child:** Simply remove it.
   - **One child:** Replace the node with its child.
   - **Two children:** Find the **inorder successor** (smallest node in the right subtree), replace the node’s data, and delete the successor.

### 🧩 Traversals
- **Inorder (Left → Root → Right)** → Produces sorted order of elements.  
- **Preorder (Root → Left → Right)** → Used to copy or serialize the tree.  
- **Postorder (Left → Right → Root)** → Used to delete or free the tree.  

### 🌲 Tree Display
The `printTree()` function prints the BST **sideways** so that the right subtree appears on top and the left on the bottom.

---

## ⚙️ How to Compile and Run

### 🧰 Requirements
- GCC compiler  
- Any IDE or terminal (Code::Blocks, VS Code, or Linux terminal)

### 🧑‍💻 Compilation Command
```bash
  EXP2.exe
