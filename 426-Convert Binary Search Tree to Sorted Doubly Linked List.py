"""
# Definition for a Node.
class Node(object):
    def __init__(self, val, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
"""
class Solution(object):
    def treeToDoublyList(self, root):
        """
        :type root: Node
        :rtype: Node
        """
        if not root:
            return None
        self.prev, self.head = None, None
        
        def inorder(node):
            if not node:
                return None
            inorder(node.left)
            if not self.head:
                self.head = node
                self.prev = node
            else:
                self.prev.right = node
                node.left = self.prev
                self.prev = node
            inorder(node.right)
        
        inorder(root)
        self.prev.right = self.head
        self.head.left = self.prev
        
        return self.head
        