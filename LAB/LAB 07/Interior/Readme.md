

# Interior-Point Method in C

This project implements a simple barrier-based Interior-Point Method for solving
linear programming problems of the form:

maximize:      cᵀx  
subject to:    A x ≤ b

The algorithm uses a logarithmic barrier term and gradient ascent to remain
strictly inside the feasible region.

---

## Overview

The program performs the following steps:

1. Reads:
   - Number of constraints (m)
   - Number of variables (n)
   - Matrix A
   - Vector b
   - Objective coefficients c

2. Initializes a feasible starting point x.

3. Uses an iterative gradient-based update that maximizes the barrier-augmented
   objective:

   Φ(x) = cᵀx − μ Σ log(b − A x)

4. Gradually decreases the barrier parameter μ.

5. Computes the final solution x and objective value cᵀx.

---

## Files Included

- `interior.c` — C implementation of a basic interior-point method  
- `README.md` — Documentation explaining the method and the algorithm flow  

---

## Compilation

Compile the program with:

```bash
interior.exe
