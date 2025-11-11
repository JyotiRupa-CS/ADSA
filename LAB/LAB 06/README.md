# 🧮 Simplex Method in C

[![Language](https://img.shields.io/badge/language-C-blue.svg)](https://en.wikipedia.org/wiki/C_(programming_language))
[![License](https://img.shields.io/badge/license-MIT-green.svg)](LICENSE)
[![Platform](https://img.shields.io/badge/platform-Windows%20%7C%20Linux%20%7C%20macOS-lightgrey.svg)]()

---

## 📘 Overview

This project implements the **Simplex Method** in C to solve **Linear Programming Problems (LPP)** of the form:

> **Maximize:**  
> Z = c₁x₁ + c₂x₂ + ... + cₙxₙ  
>
> **Subject to:**  
> a₁₁x₁ + a₁₂x₂ + ... + a₁ₙxₙ ≤ b₁  
> a₂₁x₁ + a₂₂x₂ + ... + a₂ₙxₙ ≤ b₂  
> ...  
>
> **and** x₁, x₂, ..., xₙ ≥ 0  

The program accepts all input data from the user and performs simplex iterations until an optimal solution is found.  
It displays each tableau for better understanding of the optimization process.

---

## ⚙️ Features

✅ Solves **maximization** linear programming problems  
✅ Interactive user input for all coefficients  
✅ Displays each **Simplex tableau** iteration  
✅ Detects **unbounded** solutions  
✅ Lightweight and **cross-platform compatible**

---

## 🖥️ Requirements

- **C compiler:** GCC or any standard C compiler  
- **Supported OS:** Windows, macOS, Linux  

---

## 🧑‍💻 Compilation

To compile the program using **GCC**, run:

```bash
simplex.exe
