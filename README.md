# push_swap 🧩

A C program that generates the shortest possible sequence of stack operations to sort a list of integers—mandatory project in the 42 curriculum.

---

## 📌 Overview

The goal is to sort numbers in **stack A** using a second auxiliary **stack B**, limited to just 11 operations (`sa`, `sb`, `ss`, `pa`, `pb`, `ra`, `rb`, `rr`, `rra`, `rrb`, `rrr`).  
Your program must output the operation sequence (one per line), optimizing for the **fewest moves** :contentReference[oaicite:1]{index=1}.

---

## ⚙️ Operations

- **`sa`**, **`sb`**, **`ss`** — swap top 2 elements of a stack  
- **`pa`**, **`pb`** — push top element between stacks  
- **`ra`**, **`rb`**, **`rr`** — rotate stacks upwards  
- **`rra`**, **`rrb`**, **`rrr`** — rotate stacks downwards :contentReference[oaicite:2]{index=2}

---

## 🚀 Strategy & Algorithm

1. **Simplify values** (optional): map elements to their increasing rank (0…n‑1).  
2. **Handle small input (≤ 5)** with hardcoded optimal sequences.  
3. **Main sorting** (for larger \(n\)):
   - Use **radix sort** (base‑2) or an optimized variant like the **Turk Algorithm** :contentReference[oaicite:3]{index=3}.
   - Typical steps:
     - Push chunks (or bits) to **stack B**, using efficient combined rotations (`rr`, `rrr`).
     - Once B contains a chunk, move them back to A in sorted order.

Your goal is to sort:
- ≤ 3 numbers in ≤ 3 moves
- ≤ 5 numbers in ≤ 12 moves
- 100 numbers in ≤ 700 moves (maximum score)
- 500 numbers in ≤ 5500 moves :contentReference[oaicite:4]{index=4}

---

## 🛠️ Installation

```bash
git clone https://github.com/amakarem/push_swap.git
cd push_swap
make


