# Motivation

The problem is about finding the path coverage of the tree. 

The solution can be found as follows:

## Optimal Solution

> 1. Find the number of unreachable nodes (nodes, that exceed the allowed path length).
>    - _This number is the second part of the solution_.
>    - Also nodes, that have an unreachable parent are themselves unreachable, even if they do not exceed the path length.
> 2. Find the number of inner nodes and leafs.
>    - A leaf is a node, that does not have any reachable children.
>      - That means, either the node is a classical leaf or all children are unreachable.
>    - An inner node is a node, that is neither reachable nor 
> 3. The first part of the solution is calculated as follows:
>    ```
>    max(1, #(leafs) - #(inner nodes))
>    ```
>    - At least one coach is always necessary
>    - This formula results from the criteria, that people that got motivated, support the coaches.
>      - Therefore, the `#leafs` is the number of paths.
>      - `#(inner nodes)` is simply an additional criterion.
> 
> That solution should work in O(n).

## Simple Linear Solution

Intuitively implementing this leads to a DP solution. 

> 1. Recursively find all unreachable nodes with the following pseudocode:
>    ```
>    bool mark_reachable(Tree t, Employee e, int path_length) {
>       if (path_length + e.weight > threshold) {
>           // All unreached employees are implicitly marked
>           // as unreachable.
>           return false
>       }
>    
>       e.reachable = true
>       reachable_nodes++
>       
>       reachable_children = 0
>       for (Employee subordinate : t[e]) {
>           reachable_child = mark_reachable(
>               t, subordinate, path_length + e.weight
>           )
>    
>           reachable_children += reachable_children
>       }
>    
>       if (reachable_children == 0) leafs++
>       return true
>    }
>    ```
> 2. Given the information, which nodes are leafs, simply calculate the following:
>    ```
>    unreachable_nodes = employees.size() - reachable_nodes
>    inner_nodes = reachable_nodes - leafs
>    coaches_needed = max(1, leafs - inner_nodes)
>    
>    print(coaches_needed, unreachable_nodes)
>    ```

## DP Solution 

Another possibility, which is a little less efficient, would be to apply a DP on the tree and work bottom-up:

> 1. See (1) of simple linear solution
> 2. Work in bottom-up fashion in tree, starting at the leafs:
>    ```
>    if (is_leaf()) {
>        // At least one coach is needed per employee
>        dp[e] = 1
>    } else {
>        // One coach for each child, boss supports coaches, at least one coach 
>        dp[e] = max(1, (#(reachable children) - 1)
>    }
>    ```
> 3. The solution will be found at Christian: `print(dp[1])`

In this solution, we have to iterate once more over the tree, which is not absolutely necessary, but still a viable solution.

## Example Problem

Let's have a look at the following problem, solved with the simple linear solution:

![Example Problem](./example-tree.png)