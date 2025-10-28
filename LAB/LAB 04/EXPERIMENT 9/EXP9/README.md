# 🔍 String Matching Algorithms: KMP and Rabin-Karp

## 📘 Overview
This project implements two classic string matching algorithms — **Knuth–Morris–Pratt (KMP)** and **Rabin–Karp** — in the C programming language.  
Both algorithms efficiently search for occurrences of a pattern within a given text, but they use different strategies to achieve their performance.

---

## 🧠 Algorithms Implemented

### 1. Knuth–Morris–Pratt (KMP) Algorithm
The KMP algorithm avoids re-checking previously matched characters in the text.  
It preprocesses the pattern to create a **Longest Prefix Suffix (LPS)** array, which is then used to skip unnecessary comparisons during the search.

**Key Features:**
- Time Complexity: **O(n + m)**
- Space Complexity: **O(m)** (for LPS array)
- No rechecking of characters in text

---

### 2. Rabin–Karp Algorithm
The Rabin–Karp algorithm uses **hashing** to compare substrings of the text with the pattern efficiently.  
It computes a rolling hash for each substring of the text of length equal to the pattern, reducing the time spent on character-by-character comparisons.

**Key Features:**
- Time Complexity: **O(n + m)** on average
- Space Complexity: **O(1)**
- Efficient for multiple pattern searches with the same text

---

## ⚙️ Features
- User can input both **text** and **pattern** strings.
- Implements **pattern searching** using two independent methods:
  - Knuth–Morris–Pratt (KMP)
  - Rabin–Karp
- Displays positions (indices) where the pattern occurs in the text.
- Demonstrates differences in algorithmic design and efficiency.

---

## 🏗️ Compilation and Execution

Use a C compiler such as `gcc`:

```bash
EXP9.exe
