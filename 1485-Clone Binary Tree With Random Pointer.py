# Definition for Node.
# class Node(object):
#     def __init__(self, val=0, left=None, right=None, random=None):
#         self.val = val
#         self.left = left
#         self.right = right
#         self.random = random

class Solution(object):
    def copyRandomBinaryTree(self, root):
        """
        :type root: Node
        :rtype: NodeCopy
        """
        hmap = dict()  # node:node_copy
        
        def getCopy(node):
            if not node:
                return None
            if node in hmap:
                return hmap[node]
            
            curr = NodeCopy(node.val)
            hmap[node] = curr
            curr.random = getCopy(node.random)
            if node.left:
                curr.left = getCopy(node.left)
            if node.right:
                curr.right = getCopy(node.right)
            return curr
        
        return getCopy(root)