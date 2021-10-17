# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def pathSum(self, root, targetSum):
        """
        :type root: TreeNode
        :type targetSum: int
        :rtype: int
        """
        hmap = collections.defaultdict(int)
        self.res = 0
        hmap[0] = 1
        
        def dfs(node, currSum):
            if not node:
                return 
            
            currSum += node.val
            self.res += hmap[currSum-targetSum]
            hmap[currSum] += 1
            
            dfs(node.left, currSum)
            dfs(node.right, currSum)
            
            hmap[currSum] -= 1
            
        dfs(root, 0)
        return self.res