# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def getMinimumDifference(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
# first visit

        self.res = float('inf')
        self.prev = float('inf')
        
        def dfs(node, val):
            if not node:
                return
            dfs(node.left, node.val)
            self.res = min(self.res, abs(node.val-self.prev))
            self.prev = node.val
            dfs(node.right, node.val)
        
        dfs(root, float('inf'))
        return self.res
    
# another recursive solution

        def dfs(node, mn, mx):
            if not node:
                return mx-mn
            left = dfs(node.left, mn, node.val)
            right = dfs(node.right, node.val, mx)
            return min(left, right)
        
        return dfs(root, float('-inf'), float('inf'))