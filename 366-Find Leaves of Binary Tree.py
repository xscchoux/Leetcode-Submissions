# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def findLeaves(self, root):
        """
        :type root: TreeNode
        :rtype: List[List[int]]
        """
        memo = dict()
        
        def dfs(root):
            if not root:
                return 0
            left = dfs(root.left)
            right = dfs(root.right)
            total = max(left, right) + 1
            memo[total] = memo.get(total, []) + [root.val]
            return total
        
        dfs(root)
        res = []
        for key, val in memo.items():
            res.append(val)
        return res