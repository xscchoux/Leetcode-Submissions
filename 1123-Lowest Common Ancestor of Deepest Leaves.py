# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def lcaDeepestLeaves(self, root):
        """
        :type root: TreeNode
        :rtype: TreeNode
        """
        self.deepest = 0
        self.res = root
        
        def dfs(node, level):
            if not node:
                return level-1
            self.deepest = max(level, self.deepest)
            
            leftLevel = dfs(node.left, level+1)
            rightLevel = dfs(node.right, level+1)
            
            if leftLevel == self.deepest and rightLevel == self.deepest:
                self.res = node
            return max(leftLevel, rightLevel)
        
        dfs(root, 0)
        
        return self.res