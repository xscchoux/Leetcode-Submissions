class Solution(object):
    def collectTheCoins(self, coins, edges):
        """
        :type coins: List[int]
        :type edges: List[List[int]]
        :rtype: int
        """
        N = len(edges) + 1
        indegree = [0]*N
        visited = [False]*N
        graph = defaultdict(set)
        
        for u, v in edges:
            indegree[u] += 1
            indegree[v] += 1
            graph[u].add(v)
            graph[v].add(u)
            
        coinLeaf, emptyLeaf = deque([]), deque([])
        
        for i in range(len(indegree)):
            if indegree[i] == 1:
                visited[i] = True
                indegree[i] -= 1
                if coins[i]:
                    coinLeaf.append(i)
                else:
                    emptyLeaf.append(i)
        
        while emptyLeaf:
            curr = emptyLeaf.popleft()
            for nxt in graph[curr]:
                indegree[nxt] -= 1
                if not visited[nxt] and indegree[nxt] == 1:
                    visited[nxt] = True
                    if coins[nxt] == 1:
                        coinLeaf.append(nxt)
                    else:
                        emptyLeaf.append(nxt)
        
        for i in range(len(coinLeaf)):
            curr = coinLeaf[i]
            for nxt in graph[curr]:
                indegree[nxt] -= 1
                if visited[nxt] == False and indegree[nxt] == 1:
                    visited[nxt] = True
                
        tot = 0    
        for i in range(N):
            if not visited[i]:
                tot += 1
         
        return 0 if tot == 0 else 2*(tot-1)