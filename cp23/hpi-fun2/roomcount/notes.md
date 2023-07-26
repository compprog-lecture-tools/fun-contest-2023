# Problem
Find the chromatic number (the maximum size of a clique) of a unit interval graph, which is equivalent to the maximum number of conflicting intervals.

# Solution
## First Step: Find the first/last interval
Use BFS and remember the nodes that were found last.
Since the first and last node can only be found after all nodes between them and the BFS-start node,
the last found nodes contain at least one of those.

Of these nodes, select the one with the lowest degree as the start node for the second step.
Since all nodes found with the first/last node are connected to all nodes these are connected to,
any lowest degree node is either the first/last node (green) or has the same set of neighbors and can be used interchangeably (yellow).

![interval example](end_node_example.png)

## Second Step: iterate through the intervals to find the maximum overlap
The first clique contains the start node and it's neighbors.
To get the next clique, remove the node with the lowest degree (the first node) from the graph 
and add the neighbors of the remaining node with the lowest degree to the clique.
Repeat this to iterate through all cliques and track the maximum size of any clique.
This can be implemented using a priority queue.

## Repeat until all nodes have been found
Repeat for every component.
