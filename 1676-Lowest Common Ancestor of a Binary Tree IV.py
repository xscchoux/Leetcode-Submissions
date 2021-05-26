# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def lowestCommonAncestor(self, root, nodes):
        """
        :type root: TreeNode
        :type nodes: List[TreeNode]
        """
        nodeSet = set(nodes)
        
        def dfs(node):
            if not node or node in nodeSet:
                return node
            left, right = dfs(node.left), dfs(node.right)
            
            if left and right:
                return node
            else:
                return left or right
        
        return dfs(root)