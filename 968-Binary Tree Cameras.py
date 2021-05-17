# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def minCameraCover(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """

# Solution 1
        self.res = 0
        def helper(node):
            if not node:
                return 2
            
            left = helper(node.left)
            right = helper(node.right)
            
            if left == 0 or right == 0:
                self.res += 1
                return 1            
            elif left == 1 or right == 1:
                return 2
            else:
                return 0
        
        rootVal = helper(root)
        if rootVal == 0:
            return self.res + 1
        else:
            return self.res


# Solution 2
        covered = {None}
        
        def dfs(node, parent = None):
            if not node:
                return 0
            
            result = dfs(node.left, node) + dfs(node.right, node)
            if node.left not in covered or node.right not in covered:
                covered.update({node.left, node.right, node, parent})
                result += 1
                
            return result
        
        res = dfs(root)
        
        if root not in covered:
            return res + 1
        else:
            return res