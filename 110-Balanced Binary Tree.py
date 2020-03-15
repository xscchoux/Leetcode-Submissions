# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None
#  https://www.youtube.com/watch?v=C75oWiy0bWM
class Solution(object):
    def isBalanced(self, root):
        """
        :type root: TreeNode
        :rtype: bool
        """
# O(n)
        
        self.boolean = True
        def dfs(root):
            if not root:
                return 0
            leftH = dfs(root.left)
            rightH = dfs(root.right)
            if abs(leftH-rightH) > 1:
                self.boolean = False
            return max(leftH, rightH) + 1
        dfs(root)  
        return self.boolean