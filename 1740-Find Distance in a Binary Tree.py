# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
from collections import defaultdict, deque
class Solution(object):
    def findDistance(self, root, p, q):
        """
        :type root: TreeNode
        :type p: int
        :type q: int
        :rtype: int
        """
# Method 1: build a graph then use BFS
        graph = defaultdict(list)
        
        def dfs(node, parent = None):
            if not node:
                return
            if parent:
                graph[node.val].append(parent.val)
            if node.left:
                graph[node.val].append(node.left.val)
                dfs(node.left, node)
            if node.right:
                graph[node.val].append(node.right.val)
                dfs(node.right, node)
        dfs(root)
        
        visited = set()
        visited.add(p)

        queue = deque([(p, 0)])
        
        while queue:
            currVal, step = queue.popleft()
            if currVal == q:
                return step
            for nxt in graph[currVal]:
                if nxt in visited:
                    continue
                visited.add(nxt)
                queue.append((nxt, step+1))
                

# Method 2: find lowest common ancestor (LCA) of p and q, then BFS

        def LCA(node):
            if not node:
                return None
            if node.val in (p, q):
                return node
            left, right = LCA(node.left), LCA(node.right)
            if left and right:
                return node
            else:
                return left or right
            
        nodeLCA = LCA(root)
        
        def findDist(ancestor, node):
            
            queue = deque([(ancestor,0)])
            while queue:
                for _ in range(len(queue)):
                    curr, step = queue.popleft()
                    if curr.val == node:
                        return step
                    if curr.left:
                        queue.append((curr.left, step+1))
                    if curr.right:
                        queue.append((curr.right, step+1))
        LCA(root)
        
        return findDist(nodeLCA, p) + findDist(nodeLCA, q)