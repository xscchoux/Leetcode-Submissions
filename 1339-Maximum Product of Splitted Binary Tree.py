# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def maxProduct(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        sumArr = set()
        kMod = 10**9+7
        
        def dfs(node):
            if not node:
                return 0
            left = dfs(node.left)
            right = dfs(node.right)
            curr = (left + right + node.val)
            sumArr.add(curr)
            return curr
        
        tot = dfs(root)
        res = 0
        for num in sumArr:
            res = max(res, (tot-num)*num)
         
        return res%kMod