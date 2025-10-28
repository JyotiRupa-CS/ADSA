# Heap Sort in C

This repository contains a simple implementation of the **Heap Sort** algorithm in the C programming language.  
The program takes user input for the number of elements and sorts them using the **Max Heap** approach.

---

## 🧠 Overview

Heap Sort is a **comparison-based sorting algorithm** that uses a **binary heap data structure**.  
It works by building a max heap from the input data and repeatedly extracting the largest element from the heap to build the sorted array.

### Key Steps:
1. **Build a Max Heap** from the given input array.
2. **Swap** the root (maximum value) with the last element.
3. **Heapify** the reduced heap.
4. Repeat until the array is sorted.

---

## 🧩 Features

- Takes dynamic input from the user.
- Implements both `heapify()` and `heapSort()` functions.
- Displays the sorted array at the end.
- Simple and easy-to-understand implementation.

---

## 🧮 Algorithm Complexity

| Operation        | Time Complexity |
|------------------|----------------|
| Building the Heap | O(n) |
| Heapify           | O(log n) |
| Total (Heap Sort) | O(n log n) |
| Space Complexity  | O(1) |

---

## ⚙️ Compilation & Execution

### **Step 1:** Save the code in a file, for example:
```bash
heaport.exe
