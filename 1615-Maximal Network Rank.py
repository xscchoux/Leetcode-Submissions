class Solution:
    def maximalNetworkRank(self, n: int, roads: List[List[int]]) -> int:
        graph = defaultdict(set)
        res = 0
        
        for u, v in roads:
            graph[u].add(v)
            graph[v].add(u)
            
        for i in range(n-1):
            for j in range(i+1, n):
                tmp = len(graph[i]) + len(graph[j])
                if j in graph[i]:
                    tmp -= 1
                res = max(res, tmp)
        
        return res