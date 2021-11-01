# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def delNodes(self, root, to_delete):
        """
        :type root: TreeNode
        :type to_delete: List[int]
        :rtype: List[TreeNode]
        """        
# first visited
        deleteSet = set(to_delete)
        self.res = []
        
        def dfs(node, parentExist):
            if not node:
                return 
            exist = node.val not in deleteSet
            if not parentExist and exist:
                self.res.append(node)
            dfs(node.left, exist)
            dfs(node.right, exist)
            if node.left and node.left.val in deleteSet:
                node.left = None
            if node.right and node.right.val in deleteSet:
                node.right = None
        dfs(root, False)
        return self.res
    
# simplified
        deleteSet = set(to_delete)
        self.res = []
        
        def dfs(node, parentExist):
            if not node:
                return 
            exist = node.val not in deleteSet
            if not parentExist and exist:
                self.res.append(node)
            node.left = dfs(node.left, exist)
            node.right = dfs(node.right, exist)
            return node if exist else None
        dfs(root, False)
        return self.res