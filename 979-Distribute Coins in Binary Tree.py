# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def distributeCoins(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
# https://www.cnblogs.com/grandyang/p/14188391.html
        self.res = 0
        
        def dfs(node):
            if not node:
                return 0
            left = dfs(node.left)
            right = dfs(node.right)
            self.res += abs(left) + abs(right)
            return node.val -1 + left + right
        
        dfs(root)
        
        return self.res