# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def findDuplicateSubtrees(self, root: Optional[TreeNode]) -> List[Optional[TreeNode]]:
        subID = dict()
        count = collections.defaultdict(int)
        res = []
        def dfs(node):
            if not node:
                return 0
            triplet = (dfs(node.left), node.val, dfs(node.right))
            if triplet not in subID:
                subID[triplet] = len(subID) + 1
            ID = subID[triplet]
            count[ID] += 1
            if count[ID] == 2:
                res.append(node)
            return ID
        
        dfs(root)
        return res