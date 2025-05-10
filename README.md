# C++ Data Structures and Algorithm Interactive Demo with Displayed Speed Time per Operations called + Speed Complexity Analysis and the End

## Description

This C++ program provides an interactive command-line interface to demonstrate and experiment with various fundamental data structures. It allows users to perform common operations (like insertion, deletion, display) on selected data structures and measures the time taken for each operation using `std::chrono`.

The program supports multiple data types (character, integer, double, string) through the use of C++ templates.

The program uses the fundamentals block of data structure: class, variables, and functions.

And also uses c++ pointers to efficiently use memory and optimize the speed.

## Demo

[Watch the demo on asciinema](https://asciinema.org/a/TbQWkNaVq6WXzn5WNb274hyyI)

## Features

* **Interactive Menu:** Easy-to-use menu for selecting data structures and operations.
* **Multiple Data Structures:** Implements:
    * Singly Linked List (via `sll.h`)
    * Doubly Linked List (via `dll.h`)
    * Circular Singly Linked List (via `csll.h`)
    * Circular Doubly Linked List (via `cdll.h`)
    * Array-based Stack
    * Linked List-based Stack
    * Queue (using `std::queue`)
    * Min Heap
    * Max Heap
    * Binary Search Tree
    * Undirected Graph (Adjacency List implementation)
* **Generic Programming:** Uses C++ templates (`template <typename T>`) to support various data types.
* **Performance Timing:** Measures and displays the execution time (in milliseconds) for most operations.
* **Modular Design:** Includes separate header files for linked list implementations (`sll.h`, `dll.h`, `csll.h`, `cdll.h`) and a base class/interface (`ds.h`).

## Data Structures Overview

This project implements several common data structures. Here's a brief overview of each, along with their typical use cases, advantages, and disadvantages:

---

### 1. Linked Lists (Singly, Doubly, Circular)

* **Explanation:** Linear data structures where elements (nodes) are linked using pointers.
    * **Singly:** Each node points only to the next node.
    * **Doubly:** Each node points to both the next and the previous node.
    * **Circular:** The last node points back to the first node (and vice-versa in circular doubly).
* **Use Cases:**
    * Implementing other data structures (stacks, queues).
    * Dynamic memory allocation where size is unknown beforehand.
    * Situations requiring frequent insertions/deletions in the middle (especially doubly linked lists).
    * Undo/redo functionality (doubly).
    * Round-robin scheduling (circular).
* **Pros:**
    * **Dynamic Size:** Can grow or shrink easily during runtime.
    * **Efficient Insertions/Deletions:** Generally O(1) if the position or node pointer is known (finding the position can take O(n)). No need to shift elements like in arrays.
* **Cons:**
    * **Slow Random Access:** Accessing an element by index requires traversing the list from the head (O(n)).
    * **Memory Overhead:** Requires extra memory for storing pointers (one pointer per node in singly, two in doubly).
    * **Cache Inefficiency:** Nodes might be scattered in memory, leading to poor cache locality compared to arrays.

---

### 2. Stacks (Array-based, Linked List-based)

* **Explanation:** A LIFO (Last-In, First-Out) data structure. Operations are typically `push` (add to top) and `pop` (remove from top).
    * **Array-based:** Uses a contiguous block of memory (like `std::vector`).
    * **Linked List-based:** Uses nodes linked together.
* **Use Cases:**
    * Function call management (call stack).
    * Expression evaluation (infix to postfix/prefix).
    * Undo mechanisms in software.
    * Backtracking algorithms (maze solving, recursion).
    * Browser history (back button).
* **Pros:**
    * **Array:** Good cache locality, potentially faster access due to contiguous memory. Simple implementation.
    * **Linked List:** Truly dynamic size, no risk of overflow unless memory runs out, no resizing overhead.
    * **Both:** Provide efficient O(1) time complexity for `push` and `pop` operations (amortized O(1) for array resizing).
* **Cons:**
    * **Array:** Can have fixed size or require potentially expensive resizing (O(n)) if dynamic. Risk of stack overflow if fixed size.
    * **Linked List:** Higher memory overhead per element due to pointers. Potentially slower access due to non-contiguous memory (cache misses).

---

### 3. Queue

* **Explanation:** A FIFO (First-In, First-Out) data structure. Operations are typically `enqueue` (add to rear) and `dequeue` (remove from front). This implementation uses `std::queue`.
* **Use Cases:**
    * Resource sharing (printers, CPU scheduling).
    * Asynchronous data transfer (buffers).
    * Breadth-First Search (BFS) in graphs.
    * Handling requests in order (e.g., web server requests).
* **Pros:**
    * **Fairness:** Maintains the order of arrival.
    * **Efficient Operations:** `Enqueue` and `dequeue` are typically O(1).
* **Cons:**
    * Similar to the underlying implementation (often linked lists or dynamic arrays), inheriting their memory or resizing characteristics.

---

### 4. Heaps (Min-Heap, Max-Heap)

* **Explanation:** A specialized tree-based data structure satisfying the heap property. Often implemented using arrays.
    * **Min-Heap:** The value of each node is less than or equal to the values of its children. The smallest element is at the root.
    * **Max-Heap:** The value of each node is greater than or equal to the values of its children. The largest element is at the root.
* **Use Cases:**
    * Implementing Priority Queues.
    * Heap Sort algorithm.
    * Graph algorithms like Dijkstra's (shortest path) and Prim's (minimum spanning tree).
    * Finding the k-th smallest/largest element efficiently.
* **Pros:**
    * **Efficient Find Min/Max:** O(1) access to the minimum (Min-Heap) or maximum (Max-Heap) element.
    * **Efficient Insert/Delete:** O(log n) time complexity for insertion and deletion (of the root).
    * **Space Efficient:** Can be implemented efficiently using arrays (no pointers needed).
* **Cons:**
    * **Slow Search:** Searching for an arbitrary element takes O(n) time.
    * **Not Sorted:** While partially ordered, the elements are not fully sorted.

---

### 5. Binary Search Tree (BST)

* **Explanation:** A node-based binary tree data structure where each node has a value, and for every node:
    * All nodes in the left subtree have values less than the node's value.
    * All nodes in the right subtree have values greater than the node's value.
* **Use Cases:**
    * Implementing dictionaries or associative arrays.
    * Searching, insertion, and deletion of elements.
    * Symbol tables in compilers.
    * Can be used for sorting (inorder traversal).
* **Pros:**
    * **Efficient Operations (Average Case):** Search, insertion, and deletion operations have an average time complexity of O(log n) for balanced trees.
    * **Keeps Elements Ordered:** Allows for efficient inorder traversal to retrieve elements in sorted order.
* **Cons:**
    * **Worst-Case Performance:** Can degrade to O(n) for operations if the tree becomes unbalanced (e.g., inserting sorted data). Requires balancing mechanisms (like AVL trees, Red-Black trees) for guaranteed performance, adding complexity.
    * **Implementation Complexity:** More complex to implement correctly than linear structures.

---

### 6. Graph (Undirected)

* **Explanation:** A collection of nodes (vertices) connected by edges. In an undirected graph, edges have no direction (connection is two-way). This implementation uses an adjacency list (`std::map<T, std::vector<T>>`).
* **Use Cases:**
    * Modeling networks (social networks, computer networks, road networks).
    * Representing relationships between objects.
    * Pathfinding algorithms (like BFS, DFS).
    * Recommendation systems.
* **Pros:**
    * **Versatile:** Can model a wide variety of real-world problems and relationships.
    * **Adjacency List Efficiency (for sparse graphs):** Space-efficient (O(V+E)) and efficient for finding neighbors of a vertex.
* **Cons:**
    * **Complexity:** Graph algorithms can be complex to understand and implement correctly.
    * **Adjacency List Inefficiency (for dense graphs):** Checking if an edge exists between two arbitrary vertices can take O(degree) or O(V) in the worst case, compared to O(1) for an adjacency matrix. This implementation uses a map, so edge existence check is O(log V) or O(1) average depending on map implementation, plus finding the neighbor in the vector.


## Performance Benchmarks

### Singly Linked List
- **`pushHead`**
  - **Avg. Time:** *[Value 1]*
  - **Time Complexity:** O(1)
  - **Notes:** Fast, constant time operation.
- **`pushTail`**
  - **Avg. Time:** *[Value 2]*
  - **Time Complexity:** O(n) or O(1) if tail pointer exists
  - **Notes:** Depends on tail pointer availability.
- **`popHead`**
  - **Avg. Time:** *[Value 3]*
  - **Time Complexity:** O(1)
  - **Notes:** Constant time removal from the head.
- **`readNode` (index)**
  - **Avg. Time:** *[Value 4]*
  - **Time Complexity:** O(n)
  - **Notes:** Performance depends on the node's index.
- **`deleteNode` (index)**
  - **Avg. Time:** *[Value 5]*
  - **Time Complexity:** O(n)
  - **Notes:** Deletion time increases with the index.

### Doubly Linked List
- **`pushHead`**
  - **Avg. Time:** *[Value 6]*
  - **Time Complexity:** O(1)
  - **Notes:** Constant time for adding to the head.
- **`pushTail`**
  - **Avg. Time:** *[Value 7]*
  - **Time Complexity:** O(1)
  - **Notes:** Constant time for adding to the tail.
- **`popHead`**
  - **Avg. Time:** *[Value 8]*
  - **Time Complexity:** O(1)
  - **Notes:** Efficient removal from the head.
- **`popTail`**
  - **Avg. Time:** *[Value 9]*
  - **Time Complexity:** O(1)
  - **Notes:** Efficient removal from the tail.
- **`readNode` (index)**
  - **Avg. Time:** *[Value 10]*
  - **Time Complexity:** O(n)
  - **Notes:** Performance depends on the node's index.
- **`deleteNode` (index)**
  - **Avg. Time:** *[Value 11]*
  - **Time Complexity:** O(n)
  - **Notes:** Deletion time increases with the index.

### Array Stack
- **`push`**
  - **Avg. Time:** *[Value 12]*
  - **Time Complexity:** Amortized O(1)
  - **Notes:** Constant time for insertion, amortized over multiple operations.
- **`pop`**
  - **Avg. Time:** *[Value 13]*
  - **Time Complexity:** O(1)
  - **Notes:** Constant time removal from the stack.

### Linked List Stack
- **`push`**
  - **Avg. Time:** *[Value 14]*
  - **Time Complexity:** O(1), includes `new`
  - **Notes:** Constant time for insertion with memory allocation.
- **`pop`**
  - **Avg. Time:** *[Value 15]*
  - **Time Complexity:** O(1), includes `delete`
  - **Notes:** Constant time removal with memory deallocation.

### Queue (std::queue)
- **`enqueue`**
  - **Avg. Time:** *[Value 16]*
  - **Time Complexity:** O(1)
  - **Notes:** Constant time insertion at the rear of the queue.
- **`dequeue`**
  - **Avg. Time:** *[Value 17]*
  - **Time Complexity:** O(1)
  - **Notes:** Constant time removal from the front of the queue.

### Min Heap
- **`insert`**
  - **Avg. Time:** *[Value 18]*
  - **Time Complexity:** O(log n)
  - **Notes:** Logarithmic time insertion to maintain heap property.

### Max Heap
- **`insert`**
  - **Avg. Time:** *[Value 19]*
  - **Time Complexity:** O(log n)
  - **Notes:** Logarithmic time insertion to maintain heap property.

### Binary Search Tree
- **`insert`**
  - **Avg. Time:** *[Value 20]*
  - **Time Complexity:** O(log n) avg, O(n) worst (random data?)
  - **Notes:** Logarithmic time on average; worst-case linear time if the tree becomes unbalanced.

### Graph (Adj. List)
- **`addEdge`**
  - **Avg. Time:** *[Value 21]*
  - **Time Complexity:** Depends on map/vector insertion
  - **Notes:** Time depends on the underlying data structure used for adjacency list representation.
  
---

## Prerequisites

* A C++ compiler supporting C++11 or later (e.g., g++, clang++).
* Standard C++ Library.

## Compilation

* g++ main.cpp sll.cpp dll.cpp csll.cpp cdll.cpp -o data_structures_demo

## Speed Analysis of Data Structure and Algorithm

### Devices Info Used
Since c++ are used a well fast object oriented programming language, the devices use are more significant factor at the program's speed complexity.

- processor       : 0
- BogoMIPS        : 52.00
- Features        : fp asimd evtstrm aes pmull sha1 sha2 crc32 atomics fphp asimdhp cpuid asimdrdm lrcpc dcpop asimddp
- CPU implementer : 0x41
- CPU architecture: 8
- CPU variant     : 0x2
- CPU part        : 0xd05
- CPU revision    : 0

### Observations
Records are inside the record.txt file

- **Linked Lists (Singly, Doubly, Circular)**  
  - Operations like **create**, **read**, and **update** remain consistently fast across `n = 1, 2, 3`.  
  - **Delete** time is slightly higher in singly and doubly linked lists due to traversal and pointer management.  
  - Circular variants behave similarly to their linear counterparts, with the only structural difference being tail-to-head connection.

- **Stacks**  
  - **Array Stack** has consistent push times, but **pop** times vary slightly.  
  - **Linked List Stack** shows a performance spike at `n = 2`, likely due to memory allocation or garbage collection.

- **Queue**  
  - Anomalous **enqueue** time at `n = 1` (3.1 ms) likely reflects a measurement artifact.  
  - **Dequeue** and **displayAll** are stable and efficient.

- **Heaps**  
  - Both **Min Heap** and **Max Heap** show stable and fast **insert** performance across all sizes.  
  - **displayAll** operations are moderately costly due to full array traversal.

- **Graph**  
  - **addEdge** is efficient and consistent.  
  - **displayAll** is the most expensive single operation recorded (0.17 ms), reflecting complex structure traversal.

- **Tree**  
  - **Insert** operations are fast and stable.  
  - **displayAll** is slower due to recursive traversal through tree levels.

- **Algorithms**  
  - **Sorting** on a size-7 dataset is extremely fast (< 0.005 ms).  
  - **Searching** times vary:  
    - Best case: **First Element** (0.12 ms)  
    - Average case: **Random Element** (0.066 ms)  
    - Worst case: **Last Element** (0.082 ms)

---

### General Notes

- C++ are fast if used the pointers, variables, and class together to create or implement a data structure
- This fast C++ results in insignificant ms to the operation time, variable that has the biggest factor in operation time in here is the devices used.
- All times are measured in **milliseconds (ms)**.  
- Small variations are expected due to CPU scheduling, memory allocation, or caching effects.  
- Circular linked list structures were not benchmarked separately but behave similarly to their linear counterparts.  
- These results reflect **relative speed trends**, not absolute real-world performance under all conditions.

## Valgrind (Memory Leak Benchmarking)
The whole valgrind output results are inside the valgrind.txt

### Valgrind Installation

```console
sudo apt-get install valgrind
```

Then run the program with valgrind
```console
valgrind --leak-check=full ./myprogram
```

### Valgrind Output Summary

#### Issues Detected:
1. **Conditional jump or move depends on uninitialised value(s):**
   - Triggered during memory operations in the linker (`linker64`).
   - Uninitialised stack value created in `normalize_path`.

2. **Use of uninitialised value:**
   - Detected in `memcpy` and `assign` functions, caused by uninitialized stack value in `normalize_path`.

#### Memory Leak Summary:
- **Definitely lost:** 360 bytes in 20 blocks.
- **Indirectly lost:** 32 bytes in 2 blocks.
- **Possibly lost:** 31 bytes in 1 block.
- **Still reachable:** 2,288 bytes in 7 blocks.
- **Suppressed:** 0 bytes.

#### Recommendations:
- Address uninitialized values, particularly in `normalize_path`, and review memory management to avoid leaks.
- Rerun with `--leak-check=full --show-leak-kinds=all` to identify all potential issues.
