# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def constructFromPrePost(self, preorder: List[int], postorder: List[int]) -> Optional[TreeNode]:
        
        hmap = collections.defaultdict(int)
        for i, num in enumerate(postorder):
            hmap[num] = i
        
        def dfs(i1, i2, j1, j2):
            if i1 > i2:
                return None
            rootNode = TreeNode(preorder[i1])
            if i1 == i2:
                return rootNode
            
            left = hmap[preorder[i1+1]] # last point of left tree in postorder array
            if i1 + 1 < len(preorder):
                rootNode.left = dfs(i1+1, i1+(left-j1+1), j1, left)
            if i1+(left-j1+1)+1 < len(preorder):
                rootNode.right = dfs(i1+(left-j1+1)+1, i2, left+1, j2-1)
            
            return rootNode
        
        return dfs(0, len(preorder)-1, 0, len(postorder)-1)