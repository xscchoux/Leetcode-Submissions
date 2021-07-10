# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def sumNumbers(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        self.res = 0
        def dfs(node, prev):
            if not node:
                return
            curr = 10*prev + node.val
            if not node.left and not node.right:
                self.res += curr
                return
            dfs(node.left, curr)
            dfs(node.right, curr)
        dfs(root, 0)
        return self.res