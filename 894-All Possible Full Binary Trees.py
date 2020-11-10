# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def allPossibleFBT(self, N):
        """
        :type N: int
        :rtype: List[TreeNode]
        """
# DFS
#         if N%2 == 0:
#             return []
        
#         def dfs(N):
#             if N == 1:
#                 return [TreeNode(0)]
#             trees = []
            
#             for leftNum in range(1, N-1, 2):
#                 rightNum = N-1-leftNum
#                 for leftTree in dfs(leftNum):
#                     for rightTree in dfs(rightNum):
#                         root = TreeNode(0)
#                         root.left = leftTree
#                         root.right = rightTree
#                         trees.append(root)
#             return trees
#         return dfs(N)

# DFS with memoization
        if N%2 == 0:
            return []
        
        memo = dict()
        memo[1] = [TreeNode(0)]
        
        def dfs(N):
            if N in memo:
                return memo[N]
            
            trees = []
            
            for leftNum in range(1, N-1, 2):
                rightNum = N-1-leftNum
                for leftTree in dfs(leftNum):
                    for rightTree in dfs(rightNum):
                        root = TreeNode(0)
                        root.left = leftTree
                        root.right = rightTree
                        trees.append(root)
            memo[N] = trees
            return trees
        return dfs(N)