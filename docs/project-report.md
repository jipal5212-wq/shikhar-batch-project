# Project Report: Linked List Management System

**Course:** Data Structures and Algorithms (DSA)  
**Academic Level:** 2nd Year B.Tech / BE Computer Science  
**Language:** C++ (C++11/C++17)  
**Author:** Ashish Kumar Pal  

---

## 1. Project Overview & Objective

The objective of this project is to implement a robust, comprehensive, menu-driven console application in C++ demonstrating fundamental and advanced operations on:
1. **Singly Linked List**
2. **Doubly Linked List**

The application avoids reliance on language-level collection wrappers (such as `std::list` or `std::vector`), operating directly with dynamic node allocation, pointer manipulations (`next`, `prev`, `head`, `tail`), and manual memory deallocation (`delete`).

---

## 2. Theoretical Background

A **Linked List** is a linear dynamic data structure where elements (called **Nodes**) are linked via pointers rather than occupying contiguous memory locations.

### Key Advantages over Arrays:
- Dynamic size allocation (grows and shrinks at runtime).
- $O(1)$ constant-time insertion and deletion at the beginning without element shifting.
- Efficient memory utilization without pre-allocated contiguous capacity limits.

### Node Structure:
- **Singly Node:** Contains integer data payload and a pointer to the successor (`next`).
- **Doubly Node:** Contains integer data payload, a pointer to the predecessor (`prev`), and a pointer to the successor (`next`).

---

## 3. Implemented Operations

Both the **Singly Linked List** and **Doubly Linked List** modules provide complete support for:

### Insertion Operations:
1. **Insert at Beginning:** Prepend node before `head`. $O(1)$.
2. **Insert at End:** Append node at the end. Singly: $O(n)$ traversal; Doubly: $O(1)$ via `tail`.
3. **Insert at Position:** Insert at a specified 1-based index with bounds validation.
4. **Insert After Node:** Insert a new node following the first matching target value.
5. **Insert Before Node:** Insert a new node immediately prior to the first matching target value.

### Deletion Operations:
6. **Delete from Beginning:** Remove the head node and redirect the head pointer. $O(1)$.
7. **Delete from End:** Remove the last node. Singly: $O(n)$ to reach node prior to end; Doubly: $O(1)$ via `tail`.
8. **Delete from Position:** Remove node at a 1-based index while relinking surrounding pointers.
9. **Delete by Value:** Search for the first occurrence of a value and remove its node.

### Query, Traversal & Utility Operations:
10. **Search:** Traverse from `head` and report the 1-based position of a value.
11. **Update:** Find a value and modify its payload to a new integer.
12. **Display (Forward):** Traverse using `next` links and print node sequence.
13. **Display Backward (Doubly):** Traverse using `prev` links starting from `tail`.
14. **Count Nodes:** Traverse and return the total number of active nodes.
15. **Find Maximum:** Traverse and determine the maximum value stored in the list.
16. **Find Minimum:** Traverse and determine the minimum value stored in the list.
17. **Find Middle Element:** Using Floyd's Cycle Detection / Tortoise and Hare approach (slow and fast pointers); for even lengths, returns the second middle node.
18. **Reverse:** In-place iterative reversal of pointers ($O(n)$ time, $O(1)$ auxiliary space).
19. **Sort:** Ascending order Bubble Sort by swapping adjacent node data.
20. **Remove Duplicates:** Nested traversal to remove redundant subsequent duplicate nodes while preserving initial occurrences.

---

## 4. Time & Space Complexity Analysis

| Operation | Singly Linked List | Doubly Linked List (with Tail) | Space Complexity |
|---|---|---|---|
| Insert at Beginning | $O(1)$ | $O(1)$ | $O(1)$ |
| Insert at End | $O(n)$ | $O(1)$ | $O(1)$ |
| Insert at Position | $O(n)$ | $O(n)$ | $O(1)$ |
| Insert After Node | $O(n)$ | $O(n)$ | $O(1)$ |
| Insert Before Node | $O(n)$ | $O(n)$ | $O(1)$ |
| Delete from Beginning | $O(1)$ | $O(1)$ | $O(1)$ |
| Delete from End | $O(n)$ | $O(1)$ | $O(1)$ |
| Delete from Position | $O(n)$ | $O(n)$ | $O(1)$ |
| Delete by Value | $O(n)$ | $O(n)$ | $O(1)$ |
| Search Value | $O(n)$ | $O(n)$ | $O(1)$ |
| Update Value | $O(n)$ | $O(n)$ | $O(1)$ |
| Display (Forward) | $O(n)$ | $O(n)$ | $O(1)$ |
| Display (Backward) | N/A ($O(n)$ with reversal) | $O(n)$ | $O(1)$ |
| Count Nodes | $O(n)$ | $O(n)$ | $O(1)$ |
| Find Max / Min | $O(n)$ | $O(n)$ | $O(1)$ |
| Find Middle Element | $O(n)$ | $O(n)$ | $O(1)$ |
| Reverse List | $O(n)$ | $O(n)$ | $O(1)$ |
| Sort List (Bubble Sort) | $O(n^2)$ | $O(n^2)$ | $O(1)$ |
| Remove Duplicates | $O(n^2)$ | $O(n^2)$ | $O(1)$ |

---

## 5. Architectural Comparison: Singly vs Doubly Linked List

```
Singly Linked List Node:
+------+------+     +------+------+
| Data | Next | --> | Data | Next | --> NULL
+------+------+     +------+------+

Doubly Linked List Node:
        +------+------+------+     +------+------+------+
NULL <--| Prev | Data | Next | <-> | Prev | Data | Next | --> NULL
        +------+------+------+     +------+------+------+
```

| Dimension | Singly Linked List | Doubly Linked List |
|---|---|---|
| **Pointer Overhead** | 1 pointer (`next`) per node | 2 pointers (`prev`, `next`) per node |
| **Memory Footprint** | Low (8 bytes pointer per node on 64-bit) | Higher (16 bytes pointers per node on 64-bit) |
| **Traversal** | Unidirectional (forward only) | Bidirectional (forward and backward) |
| **Node Deletion Given Node Pointer** | Requires $O(n)$ traversal to locate predecessor | $O(1)$ immediate deletion via `prev` and `next` |
| **End Operations (with Tail)** | Deletion still requires $O(n)$ traversal to find previous node | Both insertion and deletion at tail are $O(1)$ |
| **Use Cases** | Stacks, simple queues, symbol tables, low memory systems | Browser navigation history, media playlists, undo-redo buffers |

---

## 6. Edge Cases Handled

1. **Empty List Operations:** Delete, display, search, sort, reverse, and min/max on an empty list do not crash or throw segmentation faults; descriptive user notices are printed.
2. **Single-Node List:** Inserting or deleting position 1 on a single node correctly updates both `head` and `tail` to `nullptr` or the new node.
3. **Invalid Positions:** Out-of-bounds positions ($pos < 1$ or $pos > count + 1$ on insert; $pos > count$ on delete) are caught and reported.
4. **Target Not Found:** `insertAfter`, `insertBefore`, `deleteByValue`, and `update` gracefully report when the target value does not exist.
5. **Duplicate Removal:** Properly unlinks multiple consecutive or distributed duplicates without memory leaks.
6. **Robust Input Handling:** Console input errors (entering non-numeric characters) are intercepted with `cin.clear()` and `cin.ignore()`, preventing infinite loops.

---
