# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def isSymmetric(self, root):
        """
        :type root: TreeNode
        :rtype: bool
        """
        if not root:
            return True
        
        def dfs(leftNode, rightNode):
            if not leftNode and not rightNode:
                return True
            elif not leftNode or not rightNode:
                return False
            elif leftNode.val != rightNode.val:
                return False
            else:
                return dfs(leftNode.left, rightNode.right) and dfs(leftNode.right, rightNode.left)
                
        return dfs(root.left, root.right)