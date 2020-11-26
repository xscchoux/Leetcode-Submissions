# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def lowestCommonAncestor(self, root, p, q):
        """
        :type root: TreeNode
        :type p: TreeNode
        :type q: TreeNode
        :rtype: TreeNode
        """
# iterative
        while root:
            if root.val > p.val and root.val > q.val:
                root = root.left
            elif root.val < p.val and root.val < q.val:
                root = root.right
            else:
                return root
        
        return None
    
# recursive
        
        def dfs(root):
            if (root.val < p.val and root.val < q.val):
                return dfs(root.right)
            elif (root.val > p.val and root.val > q.val):
                return dfs(root.left)
            else:
                return root
        
        return dfs(root)
    