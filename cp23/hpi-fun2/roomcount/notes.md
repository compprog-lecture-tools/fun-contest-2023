# Problem
Find the chromatic number of a unit interval graph, which is equivalent to the maximum number of overlapping intervals.

# Solution
## First Step: Find the first/last interval
Use Breadth-First-Search and remember the nodes that were found last.
These are the nodes with the maximum distance to the start node.
We will refer to the node corresponding to the first/last of the intervals of nodes found in the BFS as the first/last node.
Since the first and last node can not befound before all nodes between the start node and them have been found,
the last found nodes contain at least one of those.

Of these nodes, select the one with the lowest amount of edges. 
Since the intervals of all last found nodes overlap with each other and the first and last interval do not overlap with any additional intervals,
this node is either the first or last node or only has edges to the same nodes as on of them and can be used interchangebly, since it is part of the same overlaps.

Since it is irrelevant, wether the first node, last node, or a equivalent node is used in the next step, we are gonna refer to the selected node as the first node.

## Second Step: iterate through the intervals to find the maximum overlap
Use a priority queue, that compares nodes by a score that is the amount of intervals that started, before their corresponding interval ended. Since the intervals are equal length,
the higher that score is, the later that interval occured. For the first node and all it's neighbors, the score is exactly their degree.

In each step, the nodes with the lowest score can be removed and a node with the next lowest score can be used to find the next nodes to be added to the queue.
Their score can be calculated as the sum of their edges and the number of nodes that have already been remove from the queue.
Repeat this step until no new nodes are found and track the maximum size of the queue.

## Repeat until all nodes have been found
Since the graph might not be connected, use the next node that has not been found in the BFS to restart from there.
When no more nodes are found, output the maximum tracked queue size.
