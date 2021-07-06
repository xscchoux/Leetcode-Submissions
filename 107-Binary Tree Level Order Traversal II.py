# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def levelOrderBottom(self, root):
        """
        :type root: TreeNode
        :rtype: List[List[int]]
        """
# preorder transversal
        res = []
        
        def dfs(node, level):
            if not node:
                return
            if len(res) == level:
                res.append([])
            res[level].append(node.val)
            dfs(node.left, level+1)
            dfs(node.right, level+1)
            
        dfs(root, 0)
        return res[::-1]