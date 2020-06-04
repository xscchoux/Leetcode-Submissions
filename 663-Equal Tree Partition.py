# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def checkEqualTree(self, root):
        """
        :type root: TreeNode
        :rtype: bool
        """
# O(n)
        res = []
        self.sum = 0
        def dfs(root):
            if not root:
                return 0
            left = dfs(root.left)
            right = dfs(root.right)  
            res.append(left + right + root.val)
            self.sum += root.val
            return res[-1]
            
        dfs(root)
        
        res.pop()
        return self.sum/2.0 in res