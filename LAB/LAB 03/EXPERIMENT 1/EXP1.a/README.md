# 🔍 Binary Search in C (Recursive & Non-Recursive)

This project implements **Binary Search** in **C language** using both **Recursive** and **Non-Recursive (Iterative)** methods.  
It efficiently searches for an element in a sorted array by repeatedly dividing the search interval in half.

---

## 📘 Overview

Binary Search is one of the most efficient searching algorithms for sorted arrays.  
It works on the principle of **Divide and Conquer**, reducing the search space by half at each step.

---

## 🧩 Algorithm Explanation

Let’s assume we have a sorted array `A` with indices from `low` to `high`.

1. Find the middle index:  
   \[
   \text{mid} = \text{low} + \frac{(\text{high} - \text{low})}{2}
   \]
2. Compare `A[mid]` with the target element `x`:
   - If `A[mid] == x`, the element is found.
   - If `A[mid] > x`, search the **left half** (`low` to `mid - 1`).
   - If `A[mid] < x`, search the **right half** (`mid + 1` to `high`).
3. Repeat the process until the element is found or the range becomes empty.

---

## ⚙️ Features

- Implementation of both:
  - ✅ Recursive Binary Search  
  - ✅ Non-Recursive (Iterative) Binary Search  
- Works on sorted arrays only  
- Clear user prompts and clean console output  
- Demonstrates the **Divide and Conquer** approach

---

## 🧑‍💻 Compilation & Execution

### Step 1: Save the Code
Save the source code as:
```bash
EXP1_a.exe
