"""
# Definition for a Node.
class Node(object):
    def __init__(self, val=None, children=None):
        self.val = val
        self.children = children if children is not None else []
"""

class Solution(object):
    def cloneTree(self, root):
        """
        :type root: Node
        :rtype: Node
        """
        if not root:
            return None
        
        rootCopy = Node(root.val)
        
        def dfs(node, nodeCopy):
            for nxt in node.children:
                newNode = Node(nxt.val)
                nodeCopy.children.append(newNode)
                dfs(nxt, newNode)
            
            return nodeCopy
        
        return dfs(root, rootCopy)