# 🧮 Median-of-Three Quick Sort in C

## 📘 Overview
This project implements the **Quick Sort algorithm** in **C** using the **Median-of-Three pivot selection technique**.  
Unlike the traditional approach that always picks the first or last element as a pivot, this method chooses the **median of the first, middle, and last elements**, improving partition balance and overall sorting efficiency.

---

## 🧠 Algorithm Steps
1. **Choose three elements:** first, middle, and last.
2. **Find the median** among these three — this becomes the pivot.
3. **Partition** the array such that:
   - Elements smaller than the pivot are on the left.
   - Elements larger than the pivot are on the right.
4. **Recursively** apply the same process to both partitions.
5. Continue until the entire array is sorted.

---

## 🧮 Mathematical Representation
\[
\text{mid} = \text{low} + \frac{(\text{high} - \text{low})}{2}
\]

\[
\text{pivot} = \text{Median}(A[\text{low}], A[\text{mid}], A[\text{high}])
\]

---

## ⚙️ How to Compile and Run

### 🧰 Requirements
- GCC compiler  
- Any text editor or IDE (Code::Blocks, VS Code, Dev-C++, etc.)

### 🧑‍💻 Compilation Command
```bash
EXP1_C.exe
