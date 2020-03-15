# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def isValidBST(self, root):
        """
        :type root: TreeNode
        :rtype: bool
        """
# O(n)
        _min = float('-inf')
        _max = float('inf')
        
        def dfs(root, _min, _max):
            if not root:
                return True
            if _min < root.val < _max:
                left = dfs(root.left, _min, root.val)
                right = dfs(root.right, root.val, _max)
                return left and right
            else:
                return False
        
        return dfs(root, _min, _max)