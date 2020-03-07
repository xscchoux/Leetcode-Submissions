# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def getAllElements(self, root1, root2):
        """
        :type root1: TreeNode
        :type root2: TreeNode
        :rtype: List[int]
        """
        
        def dfs(root, res):
            if not root:
                return
            dfs(root.left, res)
            res.append(root.val)
            dfs(root.right, res)
            
        res1, res2 = [], []
        
        dfs(root1,res1)
        dfs(root2, res2)
        i, j = 0, 0
        ans = []
        while i<=len(res1)-1 and j <= len(res2)-1:
            if res1[i]<=res2[j]:
                ans.append(res1[i])
                i+=1
            else:
                ans.append(res2[j])
                j+=1
                
        return ans+res1[i:]+res2[j:]