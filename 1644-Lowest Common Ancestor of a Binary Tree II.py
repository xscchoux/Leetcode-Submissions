# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def lowestCommonAncestor(self, root, p, q):
        """
        :type root: TreeNode
        :type p: TreeNode
        :type q: TreeNode
        :rtype: TreeNode
        """
        self.res = None
        
        def dfs(node):
            if not node:
                return 0
            
            cur = node == p or node == q
            
            left = dfs(node.left)
            right = dfs(node.right)
            
            if cur + left + right == 2 and not self.res:
                self.res = node
            
            return cur + left + right
        
        dfs(root)
        return self.res