# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def mergeTrees(self, t1, t2):
        """
        :type t1: TreeNode
        :type t2: TreeNode
        :rtype: TreeNode
        """
        def dfs(t1, t2):
            if not t1 and not t2:
                return None
            elif not t1:
                return t2
            elif not t2:
                return t1
            else:
                t1.val += t2.val
                t1.left = dfs(t1.left, t2.left)
                t1.right = dfs(t1.right, t2.right)
                return t1
        return dfs(t1, t2)