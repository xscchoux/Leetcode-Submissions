# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def addOneRow(self, root, v, d):
        """
        :type root: TreeNode
        :type v: int
        :type d: int
        :rtype: TreeNode
        """
        if d == 1:
            root, root.left = TreeNode(v), root
            return root
        
        def dfs(node, depth):
            if not node:
                return None
            
            if depth == 2:
                leftNode = node.left
                rightNode = node.right
                node.left = TreeNode(v)
                node.right = TreeNode(v)
                node.left.left = leftNode
                node.right.right = rightNode
                
            else:
                dfs(node.left, depth-1)
                dfs(node.right, depth-1)
            
            return node
        
        dfs(root, d)
        
        return root