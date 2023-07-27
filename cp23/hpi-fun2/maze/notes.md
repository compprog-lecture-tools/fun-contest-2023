# Maze

## Problem

In an unknown maze of dimensions w * h (1 <= w, h <= * 10^4 and 2 <= w * h <= 10^4) and an initial position find a way to the target position. The user gets the information about the surrounding fields from on oracle after each move.

## Solution

The maze with its walls can be treated as a graph. The problem can then be solved using a DFS in said graph while remembering all nodes that were already visited. If a vector is used for this it has to be twice as large for each of the given dimensions since the starting point is unclear.
