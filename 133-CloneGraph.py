"""
# Definition for a Node.
class Node(object):
    def __init__(self, val, neighbors):
        self.val = val
        self.neighbors = neighbors
"""
from collections import deque
class Solution(object):
    def cloneGraph(self, node):
        """
        :type node: Node
        :rtype: Node
        """
# DFS
        self.visited = {}
        self.dfs(node)
        return self.visited[node]
        
    def dfs(self,node):
        if node in self.visited:
            return self.visited[node]
        else:
            self.visited[node] = Node(node.val, [])
            self.visited[node].neighbors = [self.dfs(n) for n in node.neighbors]
            return self.visited[node]


# BFS
        if not node:
            return None
        queue = deque([])
        clone = Node(node.val)
        queue.append((node,clone))
        visited = dict()
        visited[node] = clone
        
        while queue:
            curr, cloneNode = queue.popleft()
            for neighbor in curr.neighbors:
                if neighbor not in visited:
                    newNode = Node(neighbor.val)
                    cloneNode.neighbors.append(newNode)
                    queue.append((neighbor, newNode))
                    visited[neighbor] = newNode
                else:
                    cloneNode.neighbors.append(visited[neighbor])
        return clone