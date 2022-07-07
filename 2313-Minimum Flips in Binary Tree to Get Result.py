# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def minimumFlips(self, root, result):
        """
        :type root: Optional[TreeNode]
        :type result: bool
        :rtype: int
        """
        
        def dfs(node):
            l_true = l_false = r_true = r_false = None
            if node.left:
                l_true, l_false = dfs(node.left)
            if node.right:
                r_true, r_false = dfs(node.right)
            
            if node.val == 0:
                return 1, 0
            elif node.val == 1:
                return 0, 1
            elif node.val == 2:
                return min(l_true+r_true, l_true+r_false, l_false+r_true), l_false+r_false
            elif node.val == 3:
                return l_true+r_true, min(l_true+r_false, l_false+r_true, l_false+r_false)
            elif node.val == 5:
                if l_true != None:
                    return l_false, l_true
                else:
                    return r_false, r_true
            else:
                return min(l_false+r_true, l_true+r_false), min(l_true+r_true, l_false+r_false)
        
        res = dfs(root)
        
        return res[0] if result else res[1]