class Solution:
    def eventualSafeNodes(self, graph: List[List[int]]) -> List[int]:
# grey-white-black algorithm
        res = []
        N = len(graph)
        color = [0]*N # 0:unvisited, 1:safe, 2:unsafe
        
        @cache
        def dfs(i):
            if color[i] == 1:
                return True
            elif color[i] == 2:
                return False
            else:
                if not graph[i]:
                    color[i] = 1
                    return True
                color[i] = 2
                for nxt in graph[i]:
                    if not dfs(nxt):
                        return False
                color[i] = 1
                return True
        
        for i in range(len(graph)):
            if dfs(i):
                res.append(i)

        return res


# topological sort, need to construct a graph first
        res = []
        N = len(graph)
        indegree = [0]*N
        adj = [[] for _ in range(N)]
        
        for i, arr in enumerate(graph):
            for node in arr:
                adj[node].append(i)
                indegree[i] += 1
                
        queue = deque([i for i in range(N) if not indegree[i]])
        
        while queue:
            for _ in range(len(queue)):
                curr = queue.popleft()
                res.append(curr)
                for nxt in adj[curr]:
                    indegree[nxt] -= 1
                    if indegree[nxt] == 0:
                        queue.append(nxt)
        
        return sorted(res)
    
