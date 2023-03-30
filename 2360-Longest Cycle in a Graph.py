class Solution(object):
    def longestCycle(self, edges):
        """
        :type edges: List[int]
        :rtype: int
        """
# DFS
        visited = [False]*len(edges)
        memo = dict()
        self.res = -1
        
        def dfs(node, dist):
            if not visited[node]:
                if node in memo:
                    self.res = max(self.res, dist-memo[node])
                elif edges[node] != -1:
                    memo[node] = dist
                    nxt = edges[node]
                    dfs(nxt, dist+1)
                visited[node] = True
                
        for i in range(len(edges)):
            dfs(i, 0)

        return self.res


# DFS2

        N = len(edges)
        visited = [False]*N
        self.res = -1
        
        def dfs(node, memo):
            if not visited[node]:
                nxt = edges[node]
                if nxt != -1:
                    if nxt in memo:
                        self.res = max(self.res, memo[node] - memo[nxt]+1)
                    else:
                        memo[nxt] = memo[node] + 1
                        dfs(nxt, memo)
                    visited[node] = True

        for i in range(N):
            memo = dict()
            memo[i] = 0
            dfs(i, memo)

        return self.res

    
# Iterative
        
        memo = dict()
        res = -1
        
        for i in range(len(edges)):
            if i in memo:
                continue
            memo[i] = (i, 0)
            queue = collections.deque([(i, 0)])
            while queue:
                curr, d = queue.popleft()
                nxt = edges[curr]
                if nxt == -1:
                    break
                if nxt in memo:
                    if memo[nxt][0] == i:
                        res = max(res, d - memo[nxt][1] + 1)
                else:
                    memo[nxt] = (i,d+1)
                    queue.append((nxt, d+1))
        return res