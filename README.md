# Linked List Management System

A comprehensive, menu-driven console application developed in C++ to demonstrate the implementation, manipulation, and analysis of **Singly Linked Lists** and **Doubly Linked Lists** from scratch without using built-in list containers.

---

## Objective

The objective of this project is to build an interactive, console-based Data Structures and Algorithms (DSA) system that demonstrates dynamic memory allocation, pointer manipulation, sequential and bidirectional traversal, and in-place node operations in C++.

---

## Language Used: C++

- **Language:** C++ (C++11 / C++17 compatible)
- **Standard Library Components:** `<iostream>`, `<limits>`, `<algorithm>`, `<string>`
- **Memory Management:** Direct heap allocation (`new`) and deallocation (`delete`)
- **Node Mechanism:** Custom pointer links (`next`, `prev`)

---

## Features

- **Interactive Menu-Driven Interface:** Clear and intuitive hierarchical menus for Singly Linked List, Doubly Linked List, and Comparative Analysis.
- **Direct Pointer Operations:** Authentic linked-list node manipulations without any auxiliary array or vector representations.
- **Safe Input Validation:** Interactive integer input sanitization protecting against infinite loops caused by unexpected character entries.
- **Edge Case Resilience:** Comprehensive handling of empty lists, single-node lists, out-of-bounds positions, missing values, duplicates, and negative numbers.
- **Clean Memory Management:** Custom destructors and clear methods preventing memory leaks.

---

## Singly Linked List

A linear collection of data elements where linear order is given by pointers. Each node contains:
- `data`: Integer payload
- `next`: Pointer pointing to the next node in the sequence (or `nullptr`)

---

## Doubly Linked List

A bidirectional linked list where each node contains:
- `data`: Integer payload
- `prev`: Pointer pointing to the previous node (or `nullptr`)
- `next`: Pointer pointing to the next node (or `nullptr`)
- Both `head` and `tail` pointers are maintained for constant-time operations at both ends.

---

## Operations

### Singly Linked List Operations
1. **Insert at Beginning** — Prepend element before head ($O(1)$)
2. **Insert at End** — Append element after the last node ($O(n)$)
3. **Insert at Position** — Insert at a 1-based position ($O(n)$)
4. **Insert After a Node** — Insert following first matching target value ($O(n)$)
5. **Insert Before a Node** — Insert immediately before first matching target value ($O(n)$)
6. **Delete from Beginning** — Remove head node ($O(1)$)
7. **Delete from End** — Remove last node ($O(n)$)
8. **Delete from Position** — Delete node at 1-based position ($O(n)$)
9. **Delete by Value** — Delete first matching value node ($O(n)$)
10. **Search** — Find 1-based position of target value ($O(n)$)
11. **Update** — Replace value in first matching node ($O(n)$)
12. **Display** — Print sequence (`val -> val -> ... -> NULL`) ($O(n)$)
13. **Count Nodes** — Return total count of elements ($O(n)$)
14. **Find Maximum** — Locate maximum value in list ($O(n)$)
15. **Find Minimum** — Locate minimum value in list ($O(n)$)
16. **Find Middle Element** — Slow/Fast pointer technique (second middle for even length) ($O(n)$)
17. **Reverse** — In-place pointer reversal ($O(n)$ time, $O(1)$ space)
18. **Sort** — Ascending order Bubble Sort ($O(n^2)$)
19. **Remove Duplicates** — In-place removal of redundant subsequent values ($O(n^2)$)
20. **Exit** — Return to Main Menu

### Doubly Linked List Operations
1. **Insert at Beginning** ($O(1)$)
2. **Insert at End** ($O(1)$ with tail reference)
3. **Insert at Position** ($O(n)$)
4. **Insert After a Node** ($O(n)$)
5. **Insert Before a Node** ($O(n)$)
6. **Delete from Beginning** ($O(1)$)
7. **Delete from End** ($O(1)$ with tail reference)
8. **Delete from Position** ($O(n)$)
9. **Delete by Value** ($O(n)$)
10. **Search** ($O(n)$)
11. **Update** ($O(n)$)
12. **Display Forward** (`NULL <- val <-> val -> NULL`) ($O(n)$)
13. **Display Backward** (`NULL <- val <-> val -> NULL` starting from tail) ($O(n)$)
14. **Count Nodes** ($O(n)$)
15. **Find Maximum** ($O(n)$)
16. **Find Minimum** ($O(n)$)
17. **Find Middle Element** ($O(n)$)
18. **Reverse** ($O(n)$ in-place swapping `prev` and `next`)
19. **Sort** ($O(n^2)$)
20. **Remove Duplicates** ($O(n^2)$)
21. **Exit** — Return to Main Menu

---

## How to Run

### Option 1: Modular Source Compilation (Recommended)

```bash
# Windows / Linux / macOS (MinGW or GCC)
g++ -std=c++11 -Wall -Wextra src/Main.cpp src/SinglyLinkedList.cpp src/DoublyLinkedList.cpp -o LinkedListManagement

# Run on Windows:
.\LinkedListManagement.exe

# Run on Linux / macOS:
./LinkedListManagement
```

### Option 2: Single-File Source Compilation

```bash
# Compile root project.cpp:
g++ -std=c++11 -Wall -Wextra project.cpp -o LinkedListManagement

# Run:
.\LinkedListManagement.exe
```

---

## Sample Output

### Singly Linked List Walkthrough
```text
Enter values: 40, 10, 30, 20, 50

Before Sort:
40 -> 10 -> 30 -> 20 -> 50 -> NULL

After Sort:
10 -> 20 -> 30 -> 40 -> 50 -> NULL

After Reverse:
50 -> 40 -> 30 -> 20 -> 10 -> NULL
```

### Doubly Linked List Walkthrough
```text
Forward:
NULL <- 10 <-> 20 <-> 30 <-> 40 -> NULL

Backward:
NULL <- 40 <-> 30 <-> 20 <-> 10 -> NULL
```

Full interactive session logs are available in [`sample-output/output.txt`](sample-output/output.txt).

---

## Time Complexity

| Operation | Singly Linked List | Doubly Linked List | Auxiliary Space |
|---|---|---|---|
| Insert at Beginning | $O(1)$ | $O(1)$ | $O(1)$ |
| Insert at End | $O(n)$ | $O(1)$ (with tail) | $O(1)$ |
| Insert at Position | $O(n)$ | $O(n)$ | $O(1)$ |
| Delete from Beginning | $O(1)$ | $O(1)$ | $O(1)$ |
| Delete from End | $O(n)$ | $O(1)$ (with tail) | $O(1)$ |
| Delete from Position | $O(n)$ | $O(n)$ | $O(1)$ |
| Search / Display / Count | $O(n)$ | $O(n)$ | $O(1)$ |
| Find Min / Max | $O(n)$ | $O(n)$ | $O(1)$ |
| Find Middle Element | $O(n)$ | $O(n)$ | $O(1)$ |
| Reverse | $O(n)$ | $O(n)$ | $O(1)$ |
| Bubble Sort | $O(n^2)$ | $O(n^2)$ | $O(1)$ |
| Remove Duplicates | $O(n^2)$ | $O(n^2)$ | $O(1)$ |

---

## Repository Structure

```text
Linked-List-Management-System/
├── README.md
├── project.cpp
├── .gitignore
├── src/
│   ├── Main.cpp
│   ├── SinglyLinkedList.h
│   ├── SinglyLinkedList.cpp
│   ├── DoublyLinkedList.h
│   └── DoublyLinkedList.cpp
├── sample-output/
│   └── output.txt
└── docs/
    └── project-report.md
```

---

## Author

- **Author:** Ashish Kumar Pal
- **GitHub Repository:** [https://github.com/jipal5212-wq/shikhar-batch-project.git](https://github.com/jipal5212-wq/shikhar-batch-project.git)
