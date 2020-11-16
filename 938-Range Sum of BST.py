# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def rangeSumBST(self, root, low, high):
        """
        :type root: TreeNode
        :type low: int
        :type high: int
        :rtype: int
        """
        self.res = 0
        
        def dfs(root):
            if not root:
                return
            if low <= root.val <= high:
                self.res += root.val
            if root.val > low:
                dfs(root.left)
            if root.val < high:
                dfs(root.right)
        
        dfs(root)
        return self.res