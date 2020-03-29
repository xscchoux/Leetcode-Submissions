# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def pathSum(self, root, sum):
        """
        :type root: TreeNode
        :type sum: int
        :rtype: List[List[int]]
        """
        res = []
        def dfs(root, val, target):
            if not root:
                return
            if not root.left and not root.right:
                if target - root.val == 0:
                    res.append(val+[root.val])
                return
            dfs(root.left, val + [root.val], target-root.val)
            dfs(root.right, val + [root.val], target-root.val)
        
        dfs(root, [], sum)
        
        return res