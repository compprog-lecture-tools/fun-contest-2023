# rattlegang

## Problem

Given a 3-regular bipartite Graph with 6 <= n <=10^4 vertices, find the size of the biggest matching.

## Solution

Optimal matchings on bipartite Graphs can be found via max flow-algorithm (for example Ford-Fulkerson or Dinic).

## Faster and much simpler solution

You can prove that there is always a perfect matching on k-regular bipartite graphs.
Therefore the size of the biggest matching is always n / 2.
