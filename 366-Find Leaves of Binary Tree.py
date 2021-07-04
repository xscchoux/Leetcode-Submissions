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
        res = []
        def dfs(node):
            if not node:
                return -1
            leftH = dfs(node.left)
            rightH = dfs(node.right)
            h = max(leftH, rightH) + 1
            if h == len(res):
                res.append([])
            res[h].append(node.val)
            return h
        dfs(root)
        return res