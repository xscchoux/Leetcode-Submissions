# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def maxAncestorDiff(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        
# my solution (bottom-up)
        self.res = float('-inf')
        
        def dfs(root):
            if not root:
                return float('inf'), float('-inf')
            
            leftMin, leftMax = dfs(root.left)
            rightMin, rightMax = dfs(root.right)
            
            _min = min(root.val, leftMin, rightMin)
            _max = max(root.val, rightMax, leftMax)
            self.res = max(self.res, abs(root.val-_min), abs(root.val-_max))
            return _min, _max
        
        dfs(root)
        return self.res
    
# top-down solution

        self.res = 0
        
        def dfs(root, _min, _max):
            if not root:
                return
            if _min != float('inf') and _max != float('-inf'):
                self.res = max(self.res, abs(root.val - _min), abs(root.val - _max))
            
            dfs(root.left, min(root.val, _min), max(root.val, _max))
            dfs(root.right, min(root.val, _min), max(root.val, _max))
            
        dfs(root, float('inf'), float('-inf'))
        
        return self.res