# 🧮 Strassen’s Matrix Multiplication (C Program)

This repository contains a C program that implements **Strassen’s Matrix Multiplication Algorithm** — an optimized algorithm that multiplies two square matrices faster than the conventional approach.  
It reduces computational complexity from **O(n³)** to approximately **O(n².81)** using the **divide and conquer** technique.

---

## 📘 Overview

Traditional matrix multiplication requires **n³** multiplications.  
Strassen’s algorithm improves this by cleverly reducing the number of multiplications to **7** (instead of 8), at the cost of more additions and subtractions.

---

## 🧠 Algorithm Concept

Given two square matrices **A** and **B**, each of size `n × n`, divide them into four submatrices:

\[
A = \begin{bmatrix}
A_{11} & A_{12} \\
A_{21} & A_{22}
\end{bmatrix},
\quad
B = \begin{bmatrix}
B_{11} & B_{12} \\
B_{21} & B_{22}
\end{bmatrix}
\]

Then compute the following seven products:

\[
\begin{aligned}
P_1 &= (A_{11} + A_{22})(B_{11} + B_{22}) \\
P_2 &= (A_{21} + A_{22})B_{11} \\
P_3 &= A_{11}(B_{12} - B_{22}) \\
P_4 &= A_{22}(B_{21} - B_{11}) \\
P_5 &= (A_{11} + A_{12})B_{22} \\
P_6 &= (A_{21} - A_{11})(B_{11} + B_{12}) \\
P_7 &= (A_{12} - A_{22})(B_{21} + B_{22})
\end{aligned}
\]

Finally, combine the results to get the product matrix **C**:

\[
\begin{aligned}
C_{11} &= P_1 + P_4 - P_5 + P_7 \\
C_{12} &= P_3 + P_5 \\
C_{21} &= P_2 + P_4 \\
C_{22} &= P_1 - P_2 + P_3 + P_6
\end{aligned}
\]

---

## ⚙️ Features

- Implementation of **Strassen’s Algorithm** in pure C  
- Works with **square matrices (n × n)**  
- Demonstrates **divide and conquer** recursion  
- User-defined matrix input  
- Displays the **final product matrix**

---

## 🧑‍💻 Compilation and Execution

### Step 1: Save the Code
Save your C source code as:
```bash
strassen.exe
