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

### 🚀 Strategy & Algorithm

1. **Simplify values**: Convert all input integers to an index-based range (`0` to `n - 1`) to reduce value distribution complexity.
2. **Small cases (≤ 5 elements)**: Handled with hardcoded optimal sorting logic for minimal moves.
3. **Large input (≥ 6 elements)**:
   - Built on a combination of the **Turk Algorithm** and **binary radix sort**.
   - ✨ **Custom Optimized Sorting Layer**:
     I implemented a custom sorting strategy on top of traditional radix-based approaches to:
     - Reduce the total number of operations
     - Minimize redundant stack rotations
     - Adapt dynamically to varying input patterns and ranges

This hybrid model produces efficient, constraint-respecting sequences even for larger stacks (100–500 elements), maintaining low operation counts and fast execution.


---

## 🛠️ Installation

```bash
git clone https://github.com/amakarem/push_swap.git
cd push_swap
make


