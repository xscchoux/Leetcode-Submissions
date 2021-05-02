# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def longestConsecutive(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        
# first try
#         self.res = 0
        
#         def dfs(node):
            
#             incLeft = decLeft = 0
#             incRight = decRight = 0
            
#             if node.left:
#                 inc1, dec1 = dfs(node.left)
#                 if node.val + 1 == node.left.val:
#                     decLeft = dec1
#                 elif node.val == node.left.val + 1:
#                     incLeft = inc1
            
#             if node.right:
#                 inc2, dec2 = dfs(node.right)
#                 if node.val + 1 == node.right.val:
#                     decRight = dec2
#                 elif node.val == node.right.val + 1:
#                     incRight = inc2
                    
#             self.res = max(self.res, incRight + 1 + decLeft, incLeft + 1 + decRight)
            
#             return max(incRight, incLeft)+1, max(decRight, decLeft)+1
        
#         dfs(root)
        
#         return self.res



        self.res = 0
        
        def dfs(node):
            
            inc = dec = 0
            
            if node.left:
                inc1, dec1 = dfs(node.left)
                if node.val + 1 == node.left.val:
                    dec = dec1
                elif node.val == node.left.val + 1:
                    inc = inc1
            
            if node.right:
                inc2, dec2 = dfs(node.right)
                if node.val + 1 == node.right.val:
                    dec = max(dec, dec2)
                elif node.val == node.right.val + 1:
                    inc = max(inc, inc2)
                    
            self.res = max(self.res, inc + 1 + dec)
            
            return inc+1, dec+1
        
        dfs(root)
        
        return self.res