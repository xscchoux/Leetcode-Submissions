# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def btreeGameWinningMove(self, root, n, x):
        """
        :type root: TreeNode
        :type n: int
        :type x: int
        :rtype: bool
        """
        self.left = 0
        self.right = 0
        def dfs(node):
            if not node:
                return 0
            
            if node.val == x:
                self.left = dfs(node.left)
                self.right = dfs(node.right)
                return 0
            
            return 1 + dfs(node.left) + dfs(node.right)
        
        dfs(root)
        return max(max(self.left, self.right), n-self.left-self.right-1) > n/2