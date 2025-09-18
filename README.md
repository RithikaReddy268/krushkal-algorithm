# Kruskal's Algorithm in C

This repository contains an implementation of **Kruskal's Minimum Spanning Tree (MST) algorithm** in C.

## Description
Kruskal's algorithm finds a subset of edges that forms a **tree including every vertex**, where the total weight of all the edges in the tree is minimized. It uses the **Union-Find (Disjoint Set) data structure** to detect cycles.

### Key Points
- Uses an **edges array** to store the graph: `(u, v, weight)`.
- `find()` and `Union()` functions manage connected components.
- Outputs all edges in the MST and the **total minimum cost**.

## How to Run
1. Clone the repository:
   ```bash
   git clone <your-repo-url>
   cd Kruskal-Algorithm
