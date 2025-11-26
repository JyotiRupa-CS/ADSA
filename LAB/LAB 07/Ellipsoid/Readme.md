# Ellipsoid Method in C

This project implements the Ellipsoid Method for solving linear programming
problems of the form:

maximize:      cᵀx  
subject to:    A x ≤ b

The ellipsoid method is an iterative algorithm that updates a candidate point
inside shrinking ellipsoids until all constraints are satisfied.

---

## Overview

The program performs the following steps:

1. Reads:
   - Number of constraints (m)
   - Number of variables (n)
   - Constraint matrix A
   - Constraint vector b
   - Objective coefficients c

2. Initializes a starting point x.

3. For each iteration:
   - Checks whether any constraint is violated.
   - If a constraint is violated, moves x in the opposite direction of the
     violating hyperplane.
   - If no constraint is violated, the algorithm terminates.

4. Computes the objective value cᵀx.

---

## Files Included

- `ellipsoid.c` — C implementation of the Ellipsoid Method  
- `README.md` — Documentation file explaining the algorithm and usage  

---

## Compilation

Compile using:

```bash
ellipsoid.exe
