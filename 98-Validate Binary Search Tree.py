# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def isValidBST(self, root):
        """
        :type root: TreeNode
        :rtype: bool
        """
# iterative
        stack, prev = [], float('-inf')
        while True:
            if root:
                stack.append(root)
                root = root.left
            elif stack:
                root = stack.pop()
                if root.val <= prev:
                    return False
                prev = root.val
                root = root.right
            else:
                break
        
        return True
        
# Recursive        
        def dfs(node, mx, mn):
            if not node:
                return True
            if mn < node.val and node.val < mx:
                left = dfs(node.left, node.val, mn)
                right = dfs(node.right, mx, node.val)
                
                return left and right
            else:
                return False
        
        return dfs(root, float('inf'), float('-inf'))