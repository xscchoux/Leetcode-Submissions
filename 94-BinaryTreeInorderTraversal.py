# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def inorderTraversal(self, root):
        """
        :type root: TreeNode
        :rtype: List[int]
        """
# recursive
        res = []
        def dfs(root, res):
            if root is None:
                return
            dfs(root.left, res)
            res += [root.val]
            dfs(root.right, res)

        dfs(root, res)
        return res

# iterative
        res = []
        stack = []
        while True:
            if root:
                stack.append(root)
                root = root.left
            elif stack:
                root = stack.pop()
                res.append(root.val)
                root = root.right
            else:
                break
        return res