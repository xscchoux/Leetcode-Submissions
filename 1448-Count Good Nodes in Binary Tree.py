# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def goodNodes(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        if not root:
            return 0
        self.res = 0
        def dfs(root, _max):
            if not root:
                return
            if root.val >= _max:
                _max = root.val
                self.res += 1
            dfs(root.left, _max)
            dfs(root.right, _max)
            
        dfs(root, float('-inf'))