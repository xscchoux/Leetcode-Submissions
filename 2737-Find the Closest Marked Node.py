from heapq import heappush, heappop
class Solution:
    def minimumDistance(self, n: int, edges: List[List[int]], s: int, marked: List[int]) -> int:
        dist = [float('inf')]*n
        
        graph = defaultdict(list)
        for u, v, w in edges:
            graph[u].append((v, w))
            
        pq = [(0, s)]
        
        while pq:
            d, node = heappop(pq)
            if dist[node] != float('inf'):
                continue
            dist[node] = d
            
            for nxt, weight in graph[node]:
                if dist[nxt] != float('inf'):
                    continue
                heappush(pq, (d+weight, nxt))
                
        res = float('inf')
        for node in marked:
            res = min(res, dist[node])
            
        return -1 if res == float('inf') else res