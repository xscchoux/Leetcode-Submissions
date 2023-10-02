class Solution:
    def maxKDivisibleComponents(self, n: int, edges: List[List[int]], values: List[int], k: int) -> int:
        
# My first try
        
        graph = defaultdict(list)
        for u, v in edges:
            graph[u].append(v)
            graph[v].append(u)
        
        self.root = None
        
        @cache
        def find(curr, parent):
            tot = values[curr]
            
            for nxt in graph[curr]:
                if nxt == parent:
                    continue
                val = find(nxt, curr)
                if val % k == 0:
                    self.root = (nxt, curr)
                tot += val
            return tot
        
        find(0, -1)
        if not self.root:
            return 1
        
        self.tot = 2
        
        @cache
        def dfs(curr, parent):
            tot = values[curr]
            for nxt in graph[curr]:
                if nxt == parent:
                    continue
                val = dfs(nxt, curr)
                if val % k == 0:
                    self.tot += 1
                tot += val
            return tot
        
        dfs(self.root[0], self.root[1])
        dfs(self.root[1], self.root[0])
        
        return self.tot

# BFS from leaves, hard to come up with
        graph = defaultdict(list)
        indegree = [0]*n
        res = 0
        
        for u, v in edges:
            graph[u].append(v)
            graph[v].append(u)
            indegree[u] += 1
            indegree[v] += 1
            
        queue = deque([i for i in range(n) if indegree[i] <= 1]) # find leaves or isolated nodes
        # print(queue)
        while queue:
            # print(queue)
            for _ in range(len(queue)):
                curr = queue.popleft()
                indegree[curr] -= 1   # detach current leaf
                if values[curr]%k == 0:
                    res += 1
                for nxt in graph[curr]:
                    if indegree[nxt] != 0: # the node is detached if its indegree == 0
                        indegree[nxt] -= 1  # substract indegree by 1
                        values[nxt] += values[curr]
                        if indegree[nxt] == 1:
                            queue.append(nxt)

        return res
    
    
# DFS, clever solution, easier to understand
        graph = defaultdict(list)
        visited = set()
        self.res = 0
        
        for u, v in edges:
            graph[u].append(v)
            graph[v].append(u)
            
        def dfs(curr):
            visited.add(curr)
            tot = values[curr]
            for nxt in graph[curr]:
                if nxt not in visited:
                    tot += dfs(nxt)
            if tot%k == 0:
                self.res += 1    
            return tot
            
        dfs(0)
        
        return self.res