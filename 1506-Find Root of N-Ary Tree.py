"""
# Definition for a Node.
class Node:
    def __init__(self, val=None, children=None):
        self.val = val
        self.children = children if children is not None else []
"""

class Solution:
    def findRoot(self, tree: List['Node']) -> 'Node':
        totValue = 0
        
        for node in tree:
            totValue += node.val
            for child in node.children:
                totValue -= child.val
        
        for node in tree:
            if node.val == totValue:
                return node