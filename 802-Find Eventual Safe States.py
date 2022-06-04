class Solution:
    def eventualSafeNodes(self, graph: List[List[int]]) -> List[int]:
        
        n = len(graph)
        
        # 0: unvisited, 1: safe, 2: unsafe
        color = [0]*n
        res = []

        def dfs(curr):
            if color[curr] == 2:
                return False
            elif color[curr] == 1:
                return True
            else:
                color[curr] = 2
                for nxt in graph[curr]:
                    if not dfs(nxt):
                        return False
                color[curr] = 1
                return True
                     
        for i in range(n):
            if dfs(i):
                res.append(i)
                
        return res