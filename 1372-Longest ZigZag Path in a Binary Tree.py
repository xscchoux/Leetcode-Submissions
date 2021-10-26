# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def longestZigZag(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        self.res = 0
        
        def dfs(node, direction, step):
            if not node:
                self.res = max(self.res, step-1)
                return
            
            if direction == "l":
                dfs(node.right, "r", step+1)
                dfs(node.left, "l", 1)
            else:
                dfs(node.left, "l", step+1)
                dfs(node.right, "r", 1)
        
        dfs(root.left, "l", 1)
        dfs(root.right, "r", 1)
        
        return self.res