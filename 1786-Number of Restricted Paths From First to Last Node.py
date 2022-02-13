from heapq import *
class Solution(object):
    def countRestrictedPaths(self, n, edges):
        """
        :type n: int
        :type edges: List[List[int]]
        :rtype: int
        """
# use Dijkstra's algorithm
        dist = [float('inf')]*(n+1)
        
        graph = collections.defaultdict(list)
        for u, v, w in edges:
            graph[u].append([v, w])
            graph[v].append([u, w])
            
        pq = [(0, n)]
        visited = set()
        dist[n] = 0
        
        while pq:
            distance, curr = heappop(pq)
            if curr in visited:
                continue
            visited.add(curr)
            for nxt, weight in graph[curr]:
                if distance + weight < dist[nxt]:
                    dist[nxt] = distance + weight
                    heappush(pq, (distance+weight, nxt))
        
        memo = dict()
        # used = set()
        kMod = 1000000007
        
        def dfs(start):
            if start == n:
                return 1
            if start in memo:
                return memo[start]
            ans = 0
            for nxt, _ in graph[start]:
                if dist[start] > dist[nxt]:
                    # used.add(nxt)
                    ans = (ans + dfs(nxt))%kMod
                    # used.remove(nxt)
            memo[start] = ans
            return ans
        
        return dfs(1)