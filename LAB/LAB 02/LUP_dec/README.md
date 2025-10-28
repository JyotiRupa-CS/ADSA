# LUP Decomposition in C

This repository contains a C program that performs **LUP Decomposition** (LU Decomposition with Partial Pivoting) of a given square matrix.  
The program accepts user input for a matrix of order **n × n** and computes the **Lower (L)**, **Upper (U)**, and **Permutation (P)** matrices.

---

## 🧠 Overview

**LUP Decomposition** is a matrix factorization technique where a square matrix `A` is decomposed into three matrices:

\[
PA = LU
\]

Where:  
- `P` → Permutation matrix (used for row pivoting)  
- `L` → Lower triangular matrix (with 1s on the diagonal)  
- `U` → Upper triangular matrix  

This method is more numerically stable than simple LU decomposition because it handles **pivoting**, reducing the impact of rounding errors.

---

## 🧩 Features

- Takes a **square matrix** as input directly from the user.  
- Automatically performs **partial pivoting** for numerical stability.  
- Displays all matrices (**L**, **U**, and **P**) after decomposition.  
- Handles singular matrices gracefully by displaying an error message.  

---

## 🧮 Mathematical Representation

Given a matrix `A`, the program finds matrices `L`, `U`, and `P` such that:

\[
PA = LU
\]

Example decomposition of a 3×3 matrix:

\[
A =
\begin{bmatrix}
2 & 3 & 1 \\
4 & 7 & 7 \\
-2 & 4 & 5
\end{bmatrix}
\Rightarrow
L, U, P
\]

---

## ⚙️ Compilation and Execution

### **Step 1:** Save the program as:
```bash
LUP_dec.exe
