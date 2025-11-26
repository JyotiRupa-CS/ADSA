

# KMP String Searching Algorithm in C

This project provides an implementation of the Knuth–Morris–Pratt (KMP) 
string searching algorithm in C. KMP is an efficient algorithm for finding 
occurrences of a pattern within a text.

The algorithm avoids redundant comparisons by preprocessing the pattern.

---

## Features Implemented

### ✔ LPS Array Construction
Computes the **Longest Proper Prefix which is also a Suffix (LPS)** array for 
the pattern.  
This preprocessing runs in **O(m)** time, where m is the pattern length.

### ✔ KMP Search
Searches for the pattern inside the text in **O(n + m)** time, where:
- n = length of text  
- m = length of pattern  

### ✔ User Input
The user enters:
- A text string
- A pattern string to search

---

## Algorithm Overview

KMP improves over naive string matching by not re-checking characters of the 
text. It uses the LPS array to determine how much to shift the pattern when a 
mismatch occurs.

The search phase consists of:
- Comparing characters from left to right
- Moving forward efficiently using LPS to avoid repeated comparisons



## Compilation

To compile:

```bash
KMP.exe
