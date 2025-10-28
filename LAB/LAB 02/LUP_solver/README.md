# LU Decomposition in C

This repository contains a **C program** that performs **LU Decomposition (without pivoting)** of a square matrix and solves a system of linear equations of the form:

\[
Ax = b
\]

It decomposes the input matrix `A` into **Lower (L)** and **Upper (U)** triangular matrices, then solves for the unknown vector `x` using **forward** and **backward substitution**.

---

## 🧠 Overview

**LU Decomposition** is a method used to solve systems of linear equations, invert matrices, or compute determinants efficiently.  

It expresses a matrix `A` as:

\[
A = LU
\]

Where:  
- `L` → Lower triangular matrix with 1s on the diagonal  
- `U` → Upper triangular matrix  

Once the matrix is decomposed, the system `Ax = b` becomes:

\[
LUx = b
\]

Letting `Ux = y`, we first solve **Ly = b** (forward substitution), and then **Ux = y** (backward substitution).

---

## 🧩 Features

✅ Takes any **n × n** square matrix and a vector `b` as input.  
✅ Performs **LU decomposition** without pivoting.  
✅ Solves for the vector **x** using forward and backward substitution.  
✅ Displays **L**, **U**, and **x** clearly.  
✅ Handles **zero pivot detection** with proper error messages.  

---

## 📘 Example Representation

Given:

\[
A =
\begin{bmatrix}
2 & 3 & 1 \\
4 & 7 & 7 \\
-2 & 4 & 5
\end{bmatrix}, \quad
b =
\begin{bmatrix}
1 \\
2 \\
3
\end{bmatrix}
\]

The program will find `L`, `U`, and the solution vector `x` such that:

\[
A = LU \quad \text{and} \quad Ax = b
\]

---

## ⚙️ Compilation and Execution

### **Step 1:** Save the file as  
```bash
LUP_solver.exe
