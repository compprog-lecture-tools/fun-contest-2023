# Solution notes

Given a directed, weighted graph in which you can add one edge with weight 0 between to adjacent vertices, find the shortest path between vertex 0 and n-1.

The main problem is to find the best position for the 0-weight edge. Suppose we found the shortest path, how does it look if we have a 0-weight between v and u? First, we go from vertex 0 to v on the shortest path possible, then we jump to u and then we take the shortest path to n-1. So if we have the shortest paths from 0 to all vertices and from all vertices to n, we can simply compute where to put the 0-weight edge:

- compute in degree graph of input graph
- use shortest path algorithm (e.g. Dijkstra) to compute:
    - shortest path from 0 to all vertices
    - shortest path from n-1 to all vertices using the in degree graph
- for all vertices i, compute shortest path from 0 to i and the shortest path from i+1 to n-1
- the minimal resulting path is the solution
