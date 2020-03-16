# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def closestValue(self, root, target):
        """
        :type root: TreeNode
        :type target: float
        :rtype: int
        """
        self.res = root.val
        
        def dfs(root):
            if not root:
                return
            if abs(root.val-target) < abs(self.res-target):
                self.res = root.val
            if target > root.val:
                dfs(root.right)
            else:
                dfs(root.left)
        dfs(root)
        return self.res