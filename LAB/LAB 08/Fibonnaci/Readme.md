# Fibonacci Heap in C

This project provides a simple implementation of a Fibonacci Heap in C.  
A Fibonacci Heap is a priority queue data structure consisting of a collection
of heap-ordered trees. It supports a variety of operations with very efficient
amortized time complexities.

This implementation focuses on:
- Creating a Fibonacci Heap
- Inserting nodes
- Finding the minimum element

The code is designed to be easy to understand and suitable for academic
assignments.

---

## Features Implemented

### ✔ Make-Heap
Creates an empty Fibonacci Heap.

### ✔ Insert (key)
Inserts a new node with the given key into the heap.  
Insertion runs in **O(1) amortized time**.

### ✔ Find-Min
Returns the smallest key in the heap in **O(1)** time.

---

## Data Structure Overview

A Fibonacci Heap consists of:
- A circular, doubly-linked root list containing a collection of trees  
- A pointer to the **minimum node** in the heap
- Nodes containing:
  - Key value
  - Degree (number of children)
  - Left and right sibling pointers  
  - Parent pointer  
  - Child pointer  
  - A mark bit (used for decrease-key operations)

This implementation uses a simplified version focusing on insertion and
min-query operations, which retain the essential structure of the Fibonacci
Heap while keeping the example compact.

---

## Files Included

- `fibheap_user.c`  
  C program implementing basic Fibonacci Heap operations (insert and find-min).  
  The program accepts input from the user.

- `README.md`  
  This documentation file.

---

## Compilation

To compile the program:

```bash
Fibo.exe

