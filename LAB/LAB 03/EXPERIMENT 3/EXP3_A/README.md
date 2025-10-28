# 🔢 Infix to Postfix Conversion in C

## 📘 Overview
This project implements the **Infix to Postfix Expression Conversion** using the **Stack Data Structure** in **C language**.  
It converts mathematical expressions written in **infix notation** (e.g., `A+B*C`) into **postfix notation** (e.g., `ABC*+`), which is easier for computers to evaluate.

---

## 🧠 Algorithm Summary

### 🔹 What is Infix and Postfix?
- **Infix Expression:** Operators are written between operands.  
  Example: `A + B * C`
- **Postfix Expression (Reverse Polish Notation):** Operators are written after operands.  
  Example: `A B C * +`

Postfix expressions **do not require parentheses** to define operation order.

---

## ⚙️ Algorithm Steps

1. **Initialize** an empty stack for operators.  
2. **Scan** the infix expression from left to right.  
3. **If the symbol is an operand**, add it to the postfix expression.  
4. **If the symbol is an operator:**
   - Pop operators from the stack that have **higher or equal precedence**, and add them to the postfix expression.
   - Push the current operator to the stack.  
5. **If '(' is encountered**, push it onto the stack.  
6. **If ')' is encountered**, pop from the stack until '(' is found.  
7. **Pop all remaining operators** from the stack and append to the postfix expression.  

---

## 🧮 Operator Precedence Table

| Operator | Precedence | Associativity |
|-----------|-------------|----------------|
| `^`       | 3           | Right to Left  |
| `*`, `/`  | 2           | Left to Right  |
| `+`, `-`  | 1           | Left to Right  |

---

## 🧩 Example

**Input:**  

**Process:**  
1. Scan `A` → Operand → Add to postfix → `A`  
2. Scan `+` → Push to stack  
3. Scan `B` → Operand → Add → `AB`  
4. Scan `*` → Higher precedence → Push → Stack: `+, *`  
5. Scan `C` → Operand → Add → `ABC`  
6. Pop all → `ABC*+`

**Output:**  

---

## 🧰 Program Features
- Converts **any valid infix expression** (alphanumeric operands).  
- Handles **operator precedence** and **parentheses**.  
- Detects and prevents **stack underflow/overflow**.  
- Efficient **O(n)** time complexity.

---

## ⚙️ How to Compile and Run

### 🧑‍💻 Compilation Command
```bash
EXP3_A.exe
