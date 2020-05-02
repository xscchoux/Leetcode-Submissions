# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def upsideDownBinaryTree(self, root):
        """
        :type root: TreeNode
        :rtype: TreeNode
        """
# iterative
        cur = root
        pre = None
        _next = None
        tmp = None
        
        while cur:
            _next = cur.left
            cur.left = tmp
            tmp = cur.right
            cur.right = pre
            pre = cur
            cur = _next
        return pre
    
# recursive
        if not root:
            return None
        
        def dfs(root):
            if not root.left:
                return root
            newRoot = dfs(root.left)
            root.left.left = root.right
            root.left.right = root
            root.left = None
            root.right = None
            
            return newRoot
        
        return dfs(root)