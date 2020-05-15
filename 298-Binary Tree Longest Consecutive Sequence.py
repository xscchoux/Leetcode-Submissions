# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def longestConsecutive(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        if not root:
            return 0
        self.res = 1
        prev = TreeNode(float('-inf'))
        
        def dfs(root, prev, length):
            self.res = max(self.res, length)
            if not root:
                return
            if root.val == prev.val + 1:
                length += 1
            else:
                length = 1
            dfs(root.left, root, length)
            dfs(root.right, root, length)
        
        dfs(root, prev, 1)
        
        return self.res