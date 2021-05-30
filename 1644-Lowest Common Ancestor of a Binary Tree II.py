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
# Method 1
        self.res = None
        
        def dfs(node):
            if not node:
                return 0
            
            curr = (node == p or node == q)
            left, right = dfs(node.left), dfs(node.right)
            if (curr + left + right == 2 and self.res == None):
                self.res = node
            return curr + left + right
        
        dfs(root)
        return self.res
        
# Method 2
        
        self.count = 0
        
        def dfs(node):
            if not node:
                return None
            
            left, right = dfs(node.left), dfs(node.right)
            
            if node == p or node == q:
                self.count += 1
                return node
            
            if left and right:
                return node
            else:
                if node in (p, q):
                    self.count += 1
                    return node
                else:
                    return left or right
            
        res = dfs(root)
        if self.count == 2:
            return res
        else:
            return None