from collections import defaultdict, deque
class Solution(object):
    def validTree(self, n, edges):
        """
        :type n: int
        :type edges: List[List[int]]
        :rtype: bool
        """
# Any connected graph without simple cycles is a tree.
# Construct a graph and use BFS
        if len(edges) != n-1:
            return False

        graph = defaultdict(list)
        for e1, e2 in edges:
            graph[e1].append(e2)
            graph[e2].append(e1)
            
        visited = set()
        queue = deque([])
        queue.append((0,None))
        visited.add(0)
        
        while queue:
            size = len(queue)
            for _ in range(size):
                curr, prev = queue.popleft()
                for child in graph[curr]:
                    if child == prev:
                        continue
                    if child not in visited:
                        visited.add(child)
                        queue.append((child, curr))
                    else:
                        return False
        return n == len(visited)