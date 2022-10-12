# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def splitBST(self, root, target):
        """
        :type root: TreeNode
        :type target: int
        :rtype: List[TreeNode]
        """
        
        def dfs(node, target):
            if not node:
                return [None, None]
            
            if node.val <= target:
                nxt = dfs(node.right, target)
                node.right = nxt[0]
                return [node, nxt[1]]
            else:
                nxt = dfs(node.left, target)
                node.left = nxt[1]
                return [nxt[0], node]
        
        return dfs(root, target)
        