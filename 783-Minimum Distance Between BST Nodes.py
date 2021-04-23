# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def minDiffInBST(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        def dfs(node, mn, mx):
            if not node:
                return mx-mn
            left = dfs(node.left, mn, node.val)
            right = dfs(node.right, node.val, mx)
            return min(left, right)
        
        return dfs(root, float('-inf'), float('inf'))