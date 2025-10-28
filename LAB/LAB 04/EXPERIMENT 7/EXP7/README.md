# 🧮 Huffman Coding in C

## 📘 Overview
This project implements **Huffman Coding**, a popular **lossless data compression algorithm**.  
It reads a text file, calculates the frequency of each character, builds a **Huffman Tree**, and generates binary codes to efficiently encode the data.

Huffman Coding is widely used in file compression techniques such as ZIP, JPEG, and MP3.

---

## ⚙️ Features
- Reads text data from a file  
- Computes frequency of each character  
- Builds a Huffman Tree based on character frequencies  
- Generates binary Huffman codes for each character  
- Encodes the input text using the generated codes  
- Displays the encoded data and the code table  

---

## 🧩 How the Algorithm Works
1. Count frequency of all characters in the input file.  
2. Create a priority queue (min-heap) of nodes, one per character.  
3. Extract two nodes with the smallest frequencies.  
4. Create a new internal node with a frequency equal to the sum of the two nodes.  
5. Repeat until the heap contains only one node (the root of the Huffman Tree).  
6. Traverse the tree to assign binary codes (0 and 1) to each character.  
7. Use the codes to encode the file content.

---

## 🗂️ File Structure
📁 Huffman-Coding
┣ 📜 huffman.c # Main program file
┣ 📜 input.txt # Sample text file to encode


---

## 💻 How to Run

### 1️⃣ Compile
```bash
EXP7.exe
