# ⚙️ Strassen's Matrix Multiplication Algorithm (C Implementation)

## 📘 Overview
This project implements **Strassen’s Matrix Multiplication Algorithm** in the C programming language.  
Strassen’s algorithm is an advanced divide-and-conquer method that multiplies two square matrices faster than the conventional matrix multiplication approach.

---

## 🧠 Algorithm Explanation

Strassen’s algorithm reduces the number of recursive multiplications required for two matrices.  
Instead of performing **8 multiplications** as in the naive approach, it uses only **7 recursive multiplications** and several additions/subtractions.

This optimization reduces the asymptotic time complexity from:

- **O(n³)** → **O(n^log₂7)** ≈ **O(n^2.81)**

---

## 🔢 Key Steps

1. **Divide** each input matrix into four equal-sized submatrices (quadrants).
2. **Compute** seven new matrices (P1–P7) using combinations of additions, subtractions, and recursive multiplications.
3. **Combine** the intermediate results to obtain the final product matrix.

---

## 🏗️ Features

- Implements **recursive divide-and-conquer** matrix multiplication.
- Uses **7 recursive steps** for improved performance.
- Works for **square matrices of size n × n**, where **n** is a power of 2.
- Modular design with helper functions for addition, subtraction, and recursion.

---

## 🧮 Time Complexity

| Operation | Conventional | Strassen’s |
|------------|---------------|------------|
| Multiplications | n³ | ~n^2.81 |
| Additions/Subtractions | n² | ~18n² |
| Asymptotic Complexity | O(n³) | O(n^2.81) |

---

## 🏗️ Compilation and Execution

Use any C compiler such as GCC:

```bash
EXP10.exe
