from collections import defaultdict
class Solution(object):
    def networkDelayTime(self, times, N, K):
        """
        :type times: List[List[int]]
        :type N: int
        :type K: int
        :rtype: int
        """
# Time: O(N^2 + ElogE (sort) )
# Space: O(N + E), O(N) for stack in DFS
        dist= {node: float('inf') for node in range(1,N+1)}
        
        graph = defaultdict(list)
        
        for u, v, w in times:
            graph[u].append((w,v))
            
        def dfs(K, elapsed):
            if dist[K] <= elapsed:
                return
            dist[K] = elapsed
            for child in sorted(graph[K]):
                dfs(child[1], elapsed+child[0])
        
        dfs(K, 0)
        res = max(dist.values())
        
        return -1 if res == float('inf') else res