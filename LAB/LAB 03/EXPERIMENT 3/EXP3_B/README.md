# 🧮 Postfix Expression Evaluation in C

This project implements a **Postfix Expression Evaluator** using a **Stack** in C.  
It takes a postfix (Reverse Polish Notation) expression as input and evaluates it using basic arithmetic operators.

---

## 🚀 Features

- Evaluates postfix expressions using stack operations.  
- Supports operators:  
  ➕ Addition (`+`)  
  ➖ Subtraction (`-`)  
  ✖️ Multiplication (`*`)  
  ➗ Division (`/`)  
  🧠 Exponentiation (`^`)  
- Handles real (floating-point) results using `double`.  
- Detects stack overflow and underflow conditions.

---

## 🧩 Algorithm Overview

### Postfix Expression:
In postfix notation, the **operator follows the operands**.  



### Evaluation Steps:
1. Initialize an empty stack.  
2. Scan the postfix expression from left to right.  
3. **If the symbol is an operand**, push it onto the stack.  
4. **If the symbol is an operator**, pop the top two operands from the stack.  
   - Let `val1` = first popped operand  
   - Let `val2` = second popped operand  
   - Perform `val1 operator val2` and push the result back.  
5. After scanning all symbols, the final result remains on top of the stack.

---

## ⚙️ Formula Representation

| Operator | Formula | Example | Result |
|-----------|----------|----------|---------|
| `+` | val1 + val2 | 3 4 + | 7 |
| `-` | val1 - val2 | 7 2 - | 5 |
| `*` | val1 * val2 | 3 4 * | 12 |
| `/` | val1 / val2 | 8 2 / | 4 |
| `^` | pow(val1, val2) | 2 3 ^ | 8 |

---

## 🧠 Example Execution


### Step-by-Step Evaluation:
| Step | Symbol | Action | Stack |
|------|---------|--------|--------|
| 1 | 2 | Push 2 | [2] |
| 2 | 3 | Push 3 | [2,3] |
| 3 | * | Pop 3,2 → 2*3=6 | [6] |
| 4 | 5 | Push 5 | [6,5] |
| 5 | 4 | Push 4 | [6,5,4] |
| 6 | * | Pop 4,5 → 5*4=20 | [6,20] |
| 7 | + | Pop 20,6 → 6+20=26 | [26] |
| 8 | 9 | Push 9 | [26,9] |
| 9 | - | Pop 9,26 → 26-9=17 | [17] |

Result of postfix expression: 17.00


---

## 🖥️ Compilation and Execution

### 🔧 Compile
```bash
EXP3_B.exe



