# Maze

## Problem

In an unknown maze of dimensions w * h (1 <= w, h <= * 10^4 and 2 <= w * h <= 10^4) and an initial position find a way to the target position. The user gets the information about the surrounding fields from on oracle after each move.

## Solution

The maze with its walls can be treated as a graph. The problem can then be solved using a DFS in said graph.