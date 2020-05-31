from collections import defaultdict
class Solution(object):
    def minReorder(self, n, connections):
        """
        :type n: int
        :type connections: List[List[int]]
        :rtype: int
        """
        
        graph = defaultdict(list)
        
        for end, start in connections:
            graph[start].append([end, 0])
            graph[end].append([start, 1])
            
        visited = set()
        self.res = 0
        
        def dfs(start):
            visited.add(start)
            for nxt, direction in graph[start]:
                if nxt in visited:
                    continue
                if direction == 1:
                    self.res += 1
                dfs(nxt)
        dfs(0)
        return self.res