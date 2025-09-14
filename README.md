# Binary Search Tree (BST) — Insert / Search / Delete

**Location:** `dsa-practice/day8/`

## Overview

A compact, well-documented C++ implementation of a Binary Search Tree (BST) that demonstrates the core operations:

* Insert
* Search (iterative)
* Delete (handles leaf / one-child / two-children cases)
* Traversals: Inorder, Preorder, Postorder
* Level-order (BFS)
* Simple sideways pretty-print for visualization

This repository is intentionally minimal and educational — ideal for learning and experimenting with BST logic.

## Files

* `bst.cpp` — main implementation and test/demo in `main()`.
* `README.md` — this file.

> If you renamed the file while compiling earlier (e.g. `Search.cpp`), update commands below accordingly.

## Build & Run

### Linux / macOS / WSL

```bash
g++ -std=c++17 bst.cpp -O2 -o bst
./bst
```

### Windows (MinGW / MSYS)

```powershell
g++ -std=c++17 bst.cpp -O2 -o bst.exe
.\bst.exe
```

### VS Code (task) / Other IDEs

Create a build task or configure the project to compile `bst.cpp` with C++17. Then run the produced binary from the integrated terminal.

## Example output

When run with the default sample values (`50, 30, 70, 20, 40, 60, 80`), you will see: (truncated/representative)

```
BST:
50
30
20

Inorder: 20 30 50
Preorder: 50 30 20
Postorder: 20 30 50

Level-order:
50
30 70
20 40 60 80

Search 40: Found
Search 25: Not Found

After deleting 20:
... (tree printed)

Final Inorder: ...
```

> Your local output might differ if you changed file name, modified the tree values, or used a different binary.

## How it works (short)

* **Insert:** Recursively walk left/right based on comparison and place new node at null.
* **Search:** Iteratively descend left/right until key found or null.
* **Delete:** Handle three cases:

  1. Leaf — remove node.
  2. One child — replace node with child.
  3. Two children — find inorder successor (min in right subtree), copy its key, and remove the successor.
* **Traversals:** Standard recursive implementations. Inorder of BST yields sorted order.

## Notes & Tips

* Duplicate keys are ignored in this implementation. If you want duplicates, adapt the insert logic (for example, store count or allow equal keys on one side).
* The implementation is educational and not self-balancing. Worst-case time complexity is O(n) for degenerate trees. Consider studying AVL or Red-Black Trees for balanced behavior.
* Remember to free memory (the provided `freeTree()` cleans up the heap-allocated nodes).

## Extending this project

* Add iterative traversals (stack-based inorder/preorder/postorder).
* Implement tree rotations and build an AVL tree.
* Add unit tests using a testing framework (Catch2, GoogleTest).
* Add serialization/deserialization to save/load trees.

## License

MIT — feel free to reuse and modify for learning and non-commercial projects.

  

Tell me which variant you prefer and I will update it.
