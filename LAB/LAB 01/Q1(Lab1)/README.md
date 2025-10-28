# 📊 Function Growth Comparison in C

This project demonstrates how different mathematical functions grow with respect to an input value **n**.  
It compares a set of commonly used time complexity functions such as **constant**, **logarithmic**, **linear**, **quadratic**, and **cubic** functions — all implemented and analyzed using **C programming**.

---

## 🎯 Objective

To evaluate and compare the growth rate of various mathematical functions by computing their values for a given input **n**, and then sorting them in increasing order.  
This experiment helps in understanding the **asymptotic growth behavior** of different algorithms.

---

## 🧠 Key Concepts Used

- **Function Pointers** in C  
  Used to dynamically store and call multiple mathematical functions.  

- **Structures (`struct`)**  
  Used to pair function names with their computed results.  

- **Sorting with `qsort()`**  
  Utilized to arrange the functions in ascending order based on their output values.  

- **Mathematical Operations (`math.h`)**  
  Includes operations like logarithm, power, and square root to compute function values.  

---

## ⚙️ Features

- Accepts user input for the value of **n**  
- Computes values of **12 different mathematical functions**  
- Sorts them based on growth rate  
- Displays the functions in increasing order of their values  
- Demonstrates practical use of **function pointers**, **structs**, and **standard library sorting**

---

## 🧮 Functions Compared

| #  | Function Name     | Expression           | Growth Type     |
|----|-------------------|----------------------|-----------------|
| 1  | f1(n)             | 1                    | Constant        |
| 2  | f2(n)             | log₂(n)              | Logarithmic     |
| 3  | f3(n)             | 12√n                 | Sublinear       |
| 4  | f4(n)             | 50√n                 | Sublinear       |
| 5  | f5(n)             | n^0.51               | Sublinear       |
| 6  | f6(n)             | n                    | Linear          |
| 7  | f7(n)             | 3n                   | Linear          |
| 8  | f8(n)             | 232n                 | Linear          |
| 9  | f9(n)             | n log₂n              | Quasi-linear    |
| 10 | f10(n)            | 2n³                  | Cubic           |
| 11 | f11(n)            | 100n² + 6n           | Quadratic       |
| 12 | f12(n)            | n² − 324             | Quadratic       |

---

## 🧩 Compilation and Execution

Follow the steps below to compile and execute the program on your system:

### **Step 1: Compile**
Use GCC (GNU Compiler Collection) to compile the C file:
```bash
Q1(Lab1).exe

