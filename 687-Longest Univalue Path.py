# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def longestUnivaluePath(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        self.res = 0
        
        def dfs(node):
            if not node:
                return 0
            
            leftLength, rightLength = 0, 0
            
            prevLeft = dfs(node.left)
            prevRight = dfs(node.right)
            
            if node.left and node.left.val == node.val:
                leftLength = 1 + prevLeft
            if node.right and node.right.val == node.val:
                rightLength = 1 + prevRight
            
            self.res = max(self.res, leftLength+rightLength)
            
            return max(leftLength, rightLength)
        
        dfs(root)
        
        return self.res