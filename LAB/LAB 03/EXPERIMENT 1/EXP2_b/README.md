# ⚡ Sorting Algorithms in C — Quick Sort, Merge Sort & Heap Sort

This project implements **three major sorting algorithms** — **Quick Sort**, **Merge Sort**, and **Heap Sort** — all written in the **C programming language**.  
The program takes an array of integers as input, sorts it using all three algorithms, and displays the sorted results for comparison.

---

## 📘 Overview

Sorting is one of the most fundamental operations in computer science, used to organize data efficiently.  
This project demonstrates the **divide-and-conquer** and **heap-based** approaches through:

- 🌀 **Quick Sort** – Partition-based divide and conquer  
- ⚙️ **Merge Sort** – Recursive divide and conquer with merging  
- ⛰️ **Heap Sort** – Binary heap-based sorting algorithm  

---

## 🧩 Algorithms Explained

### 🔹 Quick Sort
Quick Sort uses a **pivot** element to partition the array into two halves:  
elements less than the pivot go to the left, and elements greater go to the right.  
The process is applied recursively.

**Formula:**
\[
T(n) = T(k) + T(n - k - 1) + O(n)
\]

- **Best Case:** O(n log n)  
- **Average Case:** O(n log n)  
- **Worst Case:** O(n²)

---

### 🔹 Merge Sort
Merge Sort divides the array into halves, recursively sorts them, and merges the sorted halves into a single sorted array.

**Recurrence Relation:**
\[
T(n) = 2T(n/2) + O(n)
\]

- **Best Case:** O(n log n)  
- **Average Case:** O(n log n)  
- **Worst Case:** O(n log n)

---

### 🔹 Heap Sort
Heap Sort uses a **binary heap structure** to repeatedly extract the maximum element and build the sorted array.

**Heap Property:**
\[
Parent(i) \geq Child(i)
\]

- **Best Case:** O(n log n)  
- **Average Case:** O(n log n)  
- **Worst Case:** O(n log n)

---

## 🧠 Comparison of Sorting Algorithms

| Algorithm   | Approach            | Time Complexity (Avg) | Space Complexity | Stability | Recursive |
|--------------|--------------------|------------------------|------------------|------------|------------|
| Quick Sort   | Divide & Conquer   | O(n log n)             | O(log n)         | ❌ No       | ✅ Yes      |
| Merge Sort   | Divide & Conquer   | O(n log n)             | O(n)             | ✅ Yes      | ✅ Yes      |
| Heap Sort    | Binary Heap        | O(n log n)             | O(1)             | ❌ No       | ❌ No       |

---

## ⚙️ Compilation and Execution

### Step 1: Save the File
Save your C source code as:
```bash
EXP1_b.exe
