from bisect import bisect_left, bisect_right
# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def closestNodes(self, root, queries):
        """
        :type root: Optional[TreeNode]
        :type queries: List[int]
        :rtype: List[List[int]]
        """
        nums = []
        res = []
        def dfs(node):
            if not node:
                return
            dfs(node.left)
            nums.append(node.val)
            dfs(node.right)
        dfs(root)
        
        for q in queries:
            arr = []
            mnInd = bisect_right(nums, q) - 1
            if mnInd == -1:
                arr.append(-1)
            else:
                arr.append(nums[mnInd])
            
            mxInd = bisect_left(nums, q)
            if mxInd == len(nums):
                arr.append(-1)
            else:
                arr.append(nums[mxInd])
            res.append(arr) 
        return res