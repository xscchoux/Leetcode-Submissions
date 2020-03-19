# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def rob(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        
# DFS + memo  Time complexity: O(N), space complexity:O(N) 
        memo = {}
        
        def dfs(root):
            if not root:
                return 0
            if root in memo:
                return memo[root]
            
            value = 0
            if root.left:
                value += dfs(root.left.left) + dfs(root.left.right)
            if root.right:
                value += dfs(root.right.left) + dfs(root.right.right)
            
            memo[root] = max(root.val + value, dfs(root.left)+dfs(root.right))
            return memo[root]
        
        return dfs(root)

# without memo
        def dfs(root):
            if not root:
                return [0,0]   #[max at this node, max without this node]
            
            leftRob, leftNoRob = dfs(root.left)
            rightRob, rightNoRob = dfs(root.right)
            
            return max(root.val + leftNoRob + rightNoRob, leftRob+rightRob), leftRob + rightRob
        
        return max(dfs(root))