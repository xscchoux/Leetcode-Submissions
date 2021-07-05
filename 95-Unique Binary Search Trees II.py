# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def generateTrees(self, n):
        """
        :type n: int
        :rtype: List[TreeNode]
        """
        memo = dict()
        
        def dfs(start, end):
            if end < start:
                return [None]
            if start == end:
                return [TreeNode(start)]
            if (start, end) in memo:
                return memo[(start, end)]
            subTree = []
            for i in range(start, end+1):
                currNode = TreeNode(i)
                for leftSubTree in dfs(start, i-1):
                    currNode.left = leftSubTree
                    for rightSubTree in dfs(i+1, end):
                        currNode.right = rightSubTree
                        subTree.append(copy.copy(currNode))
            memo[(start, end)] = subTree
            return subTree

        return dfs(1, n)

# without using copy

        memo = dict()
        
        def dfs(start, end):
            if end < start:
                return [None]
            if start == end:
                return [TreeNode(start)]
            if (start, end) in memo:
                return memo[(start, end)]
            subTree = []
            for i in range(start, end+1):
                for leftSubTree in dfs(start, i-1):
                    for rightSubTree in dfs(i+1, end):
                        currNode = TreeNode(i)
                        currNode.left = leftSubTree
                        currNode.right = rightSubTree
                        subTree.append(currNode)
            memo[(start, end)] = subTree
            return subTree

        return dfs(1, n)