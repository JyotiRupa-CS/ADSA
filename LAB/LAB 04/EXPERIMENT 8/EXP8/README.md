# Longest Common Subsequence (LCS) in C

## 📘 Overview
This program finds the **Longest Common Subsequence (LCS)** and **all common subsequences** between two input strings using **Dynamic Programming** and **recursion** techniques.

The **Longest Common Subsequence (LCS)** problem is a classic computer science problem that aims to determine the longest sequence that appears in the same relative order (but not necessarily contiguous) in both strings.

---

## ⚙️ Features
- Computes the **length of the LCS**.
- Displays **one LCS** using backtracking.
- Generates **all possible common subsequences**.
- User-friendly implementation with clear logic flow.
- Uses **Dynamic Programming** for efficient computation.

---

## 🧠 Algorithm Used
1. **Dynamic Programming Table Construction**
   - Builds a 2D table where `dp[i][j]` represents the LCS length of prefixes `X[0..i-1]` and `Y[0..j-1]`.
2. **Backtracking**
   - Reconstructs one LCS from the filled DP table.
3. **Recursion**
   - Enumerates all possible common subsequences by exploring all matching character positions recursively.

---

## 🧩 Files
| File Name | Description |
|------------|-------------|
| `lcs.c` | Contains the main program logic for finding LCS and all common subsequences |
| `README.md` | Documentation and description of the project |

---

## 🏗️ How to Compile
Use any C compiler (like GCC) to compile the program:
```bash
EXP8.exe
