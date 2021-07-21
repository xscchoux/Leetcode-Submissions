# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def rightSideView(self, root):
        """
        :type root: TreeNode
        :rtype: List[int]
        """
# BFS
        if not root:
            return []
        
        res = []
        queue = collections.deque([root])
        
        while queue:
            size = len(queue)
            for i in range(size):
                curr = queue.popleft()
                if i == size-1:
                    res.append(curr.val)
                if curr.left:
                    queue.append(curr.left)
                if curr.right:
                    queue.append(curr.right)
        return res

# DFS
        res = []
        def dfs(node, depth):
            if not node:
                return
            if depth == len(res):
                res.append(node.val)
            dfs(node.right, depth+1)
            dfs(node.left, depth+1)
        
        dfs(root, 0)
        return res