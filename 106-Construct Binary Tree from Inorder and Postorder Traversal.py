# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def buildTree(self, inorder, postorder):
        """
        :type inorder: List[int]
        :type postorder: List[int]
        :rtype: TreeNode
        """
        N = len(inorder)
        hmap = {val: ind for ind, val in enumerate(inorder)}
        
        def dfs(start1, end1, start2, end2):
            if end1 < start1:
                return None
            
            root = TreeNode(postorder[end1])
            rootIndex = hmap[postorder[end1]]
            
            rightLen = end2 - rootIndex
            
            root.left = dfs(start1, end1-rightLen-1, start2, rootIndex-1)
            root.right = dfs(end1-rightLen, end1-1, rootIndex+1, end2)
            
            return root
        
        return dfs(0, N-1, 0, N-1)

# better way

        hmap = {val: ind for ind, val in enumerate(inorder)}
            
        def dfs(start, end):
            if start > end:
                return None
            rootVal = postorder.pop()
            root = TreeNode(rootVal)
            
            Idx = hmap[rootVal]
            root.right = dfs(Idx+1, end)
            root.left = dfs(start, Idx-1)
            
            return root
        
        return dfs(0, len(inorder)-1)