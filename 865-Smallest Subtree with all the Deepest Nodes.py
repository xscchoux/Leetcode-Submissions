# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def subtreeWithAllDeepest(self, root: TreeNode) -> TreeNode:
# first try
#         def maxH(node):
#             if not node:
#                 return 0
#             return 1 + max(maxH(node.left), maxH(node.right))
        
#         maxHeight = maxH(root)
#         self.res = root
        
#         def dfs(node, level):
#             if not node:
#                 return 0
            
#             left = dfs(node.left, level+1)
#             right = dfs(node.right, level+1)
#             if left == right and left + level+1 == maxHeight:
#                 self.res = node
                
#             return 1 + max(left, right)
        
#         dfs(root, 0)
        
#         return self.res

# another
        @cache
        def maxH(node):
            if not node:
                return 0
            return 1 + max(maxH(node.left), maxH(node.right))
        
        maxH(root)
        node = root
        
        while node:
            left, right = maxH(node.left), maxH(node.right)
            if left == right:
                return node
            elif left > right:
                node = node.left
            else:
                node = node.right
        
        return node