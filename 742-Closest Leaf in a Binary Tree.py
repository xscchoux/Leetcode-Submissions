# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

from collections import defaultdict, deque
class Solution(object):
    def findClosestLeaf(self, root, k):
        """
        :type root: TreeNode
        :type k: int
        :rtype: int
        """

# construct the graph
        graph = defaultdict(list)
        queue = deque([])
        def dfs(root, par=None):
            if not root:
                return
            if root.val == k:
                queue.append(root)
            graph[par].append(root)
            graph[root].append(par)
            dfs(root.left, root)
            dfs(root.right, root)
        dfs(root)   
        
        seen = set(queue)
        while queue:
            size = len(queue)
            node = queue.popleft()
            if node:                    # note that there would be "None" nodes
                if len(graph[node]) <= 1:  # note that root has a childNode "None", and all leaf node has only one neighbor
                    return node.val
                for nei in graph[node]:
                    if nei not in seen:
                        seen.add(nei)
                        queue.append(nei)