# Solution notes

Given a directed, weighted graph in which you can add one edge with weight 0 between to adjacent vertices, find the shortest path between vertex 0 and n-1.


- use shortest path algorithm (e.g. Dijkstra) to compute:
    - shortest path from 0 to all vertices
    - shortest path from n-1 to all vertices on the transpose graph
- for all vertices i, compute shortest path from 0 to i and the shortest path from i+1 to n-1
- the minimal resulting path is the solution
