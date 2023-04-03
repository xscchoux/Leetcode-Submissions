class Solution:
    def findShortestCycle(self, n: int, edges: List[List[int]]) -> int:
        # DFS, note that we need to make a copy of dictionary in Python 
        graph = defaultdict(list)
        visited = set()
        self.res = n + 1
        
        for u, v in edges:
            graph[u].append(v)
            graph[v].append(u)
        
        def dfs(curr, parent, memo):
            if len(memo) > self.res:     # pruning
                return
            visited.add(curr)
            
            for nxt in graph[curr]:
                if nxt == parent:
                    continue
                if nxt in memo:
                    self.res = min(self.res, memo[curr] - memo[nxt] + 1)
                else:
                    memo_copy = memo.copy()
                    memo_copy[nxt] = memo_copy[curr] + 1
                    dfs(nxt, curr, memo_copy)
                
        for i in range(n):
            if i not in visited:
                dfs(i, -1, {i:0})

        return -1 if self.res == n+1 else self.res
    

# BFS
        graph = defaultdict(list)
        hmap = dict()
        res = n + 1
        
        for u, v in edges:
            graph[u].append(v)
            graph[v].append(u)
            
        for i in range(n):
            queue = deque([(i, -1, 0)]) # current node, parent node, steps made
            hmap = dict()
            while queue:
                curr, parent, step = queue.popleft()
                hmap[curr] = step
                for nxt in graph[curr]:
                    if nxt == parent:
                        continue
                    if nxt in hmap:
                        res = min(res, hmap[curr] + hmap[nxt] + 1)
                        break    # shortest cycle that starts with i
                    else:
                        if step + 1 < res:
                            queue.append((nxt, curr, step+1))

        return -1 if res == n+1 else res