class Solution:
    def maximumCost(self, n: int, highways: List[List[int]], k: int) -> int:
        graph = collections.defaultdict(list)
        for u, v, w in highways:
            graph[u].append((v, w))
            graph[v].append((u, w))
        
        @cache
        def dfs(curr, length, mask):
            if length == k:
                return 0
            res = float('-inf')
            found = False
            for nxt, weight in graph[curr]:
                if (mask >> nxt) & 1:
                    continue
                found = True
                res = max(res, weight + dfs(nxt, length+1, mask^(1<<nxt)))
            if found:
                return res
            return float('-inf')
                
        ans = -1
        for i in range(n):
            ans = max(ans, dfs(i, 0, 1<<i))
        
        return ans