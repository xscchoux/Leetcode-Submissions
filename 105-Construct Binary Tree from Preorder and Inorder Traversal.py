# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def buildTree(self, preorder, inorder):
        """
        :type preorder: List[int]
        :type inorder: List[int]
        :rtype: TreeNode
        """
        N = len(preorder)
        hmap = {val:ind for ind, val in enumerate(inorder)}
        
        def dfs(start1, end1, start2, end2):
            if start1 > end1:
                return None
            
            root = TreeNode(preorder[start1])
            rootIndex = hmap[preorder[start1]]
            leftRange = rootIndex - start2
            rightRange = end2 - rootIndex - 1
            
            root.left = dfs(start1+1, start1+leftRange , start2, rootIndex-1)
            root.right = dfs(end1-rightRange, end1, rootIndex+1, end2)
            
            return root
        
        return dfs(0, N-1, 0, N-1)