# rattlegang

## Problem

Given a 3-regular bipartite Graph with 6 <= n <=10^6 vertices, find the size of the maximum matching.

## First solution idea

Optimal matchings on bipartite Graphs can be found via max flow-algorithm (for example Ford-Fulkerson or Dinic).
However, given the input size, this is too slow. 

## Faster and much simpler solution

It can be proven that there is always a perfect matching on k-regular bipartite graphs.
Therefore the size of the maximum matching is always n / 2.
