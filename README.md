# 🧠 push_swap

An efficient stack-sorting algorithm using two stacks and a limited set of operations.  
This project is part of the [42 School](https://42.fr/) curriculum and focuses on algorithm optimization, data structure manipulation, and sorting strategies.

---

## 📌 Project Overview

The goal of **push_swap** is to sort a stack of integers in ascending order with the **fewest possible operations**, using only a predefined set of instructions and **two stacks (A and B)**.

You must implement an algorithm that:
- Sorts the list correctly.
- Uses as few operations as possible.
- Handles various input sizes (small and large stacks efficiently).
- Has no memory leaks and handles invalid inputs gracefully.

---

## ⚡ Allowed Instructions

- **sa / sb / ss** — swap the top elements of stacks A and/or B  
- **pa / pb** — push the top element from one stack to the other  
- **ra / rb / rr** — rotate stack upwards  
- **rra / rrb / rrr** — rotate stack downwards

---

## 🧮 Algorithm

The project challenges you to find efficient sorting strategies. Common approaches include:
- **Simple sorting** for small stacks (≤ 5 elements).
- **Radix sort** for larger stacks (e.g., 100 or 500 elements).

---

## 🧪 Usage

### 1️⃣ **Clone the repository**

```bash
git clone https://github.com/your-username/push_swap.git
cd push_swap
```
### 1️⃣ **Compile**

```bash
make
```
### 1️⃣ **Run**

```bash
./push_swap 4 67 3 87 23
```
### 1️⃣ **Check with the provided checker**

```bash
./push_swap 2 1 3 6 5 8 | ./checker 2 1 3 6 5 8
```

## 🧰 Makefile Targets

make → Compile push_swap

make clean → Remove object files

make fclean → Remove object files and binary

make re → Recompile from scratch


