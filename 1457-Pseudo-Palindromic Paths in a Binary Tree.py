# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def pseudoPalindromicPaths (self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        self.res = 0
        
        def dfs(node, curr):
            if not node:
                return
            curr = curr^(1<<node.val)
            if not node.left and not node.right:
                if curr&(curr-1) == 0:
                    self.res += 1
                return
            dfs(node.left, curr)
            dfs(node.right, curr)
        
        dfs(root, 0)
        
        return self.res