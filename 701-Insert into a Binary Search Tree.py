# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def insertIntoBST(self, root, val):
        """
        :type root: TreeNode
        :type val: int
        :rtype: TreeNode
        """
# iterative
        if not root:
            return TreeNode(val)
        
        curr = root
        while curr:
            prev = curr
            if val > curr.val:
                curr = curr.right
                if not curr:
                    prev.right = TreeNode(val)
            else:
                curr = curr.left
                if not curr:
                    prev.left = TreeNode(val)
        
        return root

# recursive
        def helper(root):
            if not root:
                return TreeNode(val)
            
            if val > root.val:
                root.right = helper(root.right)
            else:
                root.left = helper(root.left)
            return root
        
        return helper(root)