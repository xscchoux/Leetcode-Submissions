# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def convertBST(self, root):
        """
        :type root: TreeNode
        :rtype: TreeNode
        """
# recursive
        self.res = 0
        def dfs(root):
            if not root:
                return
            dfs(root.right)
            self.res += root.val
            root.val = self.res
            dfs(root.left)
        
        dfs(root)
        return root
            
# iterative
        stack = []
        val = 0
        node = root 
        while True:
            if node:
                stack.append(node)
                node = node.right
            elif stack:
                node = stack.pop()
                node.val += val
                val = node.val
                node = node.left
            else:
                break
        
        return root