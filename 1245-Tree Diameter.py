from collections import defaultdict
class Solution(object):
    def treeDiameter(self, edges):
        """
        :type edges: List[List[int]]
        :rtype: int
        """
        graph = defaultdict(list)
        
        for u, v in edges:
            graph[u].append(v)
            graph[v].append(u)
        
        leaves = []

        self.res = 0
        self.goal = None

        def dfs(start, res):
            if res > self.res:
                self.res = res
                self.goal = start
            for _next in graph[start]:
                if _next not in visited:
                    visited.add(_next)
                    dfs(_next, res+1)
                    
        visited = {0}
        dfs(0, 0)
        
        visited = {self.goal}
        dfs(self.goal, 0)
            
        return self.res