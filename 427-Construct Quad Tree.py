"""
# Definition for a QuadTree node.
class Node:
    def __init__(self, val, isLeaf, topLeft, topRight, bottomLeft, bottomRight):
        self.val = val
        self.isLeaf = isLeaf
        self.topLeft = topLeft
        self.topRight = topRight
        self.bottomLeft = bottomLeft
        self.bottomRight = bottomRight
"""

class Solution:
    def construct(self, grid: List[List[int]]) -> 'Node':
        row, col = len(grid), len(grid[0])
        
        def dfs(startR, startC, length):
            if length == 1:
                return Node(grid[startR][startC], True)

            kids = [
                dfs(startR, startC, length//2),
                dfs(startR, startC+length//2, length//2),
                dfs(startR+length//2, startC, length//2),
                dfs(startR+length//2, startC+length//2, length//2)
            ]

            if all(kid.isLeaf for kid in kids) and len(set(kid.val for kid in kids)) == 1:
                return Node(kids[0].val, True)
            else:
                return Node("*", False, *kids)
            
        return dfs(0, 0, len(grid))        
