# Bellman-Ford, O(n*m), m:number of edges
class Solution:
    def maxProbability(self, n: int, edges: List[List[int]], succProb: List[float], start: int, end: int) -> float:
        maxProb = [0]*n
        maxProb[start] = 1
        
        for _ in range(n-1):
            update = False
            for i in range(len(edges)):
                u, v = edges[i]
                if maxProb[u] < maxProb[v]*succProb[i]:
                    maxProb[u] = maxProb[v]*succProb[i]
                    update = True
                if maxProb[v] < maxProb[u]*succProb[i]:
                    maxProb[v] = maxProb[u]*succProb[i]
                    update = True
            if not update:
                break
        
        return maxProb[end]
        
# Dijkstra's algorithm
from heapq import heappush, heappop
class Solution:
    def maxProbability(self, n: int, edges: List[List[int]], succProb: List[float], start: int, end: int) -> float:
        prob = [0]*n
        
        graph = defaultdict(list)
        for i in range(len(edges)):
            u, v = edges[i]
            w = succProb[i]
            graph[u].append((v, w))
            graph[v].append((u, w))
            
        pq = [(-1, start)]  # probabilitiy
        
        while pq:
            p, idx = heappop(pq)
            if prob[idx] != 0:
                continue
            if idx == end:
                return -p
            prob[idx] = -p
            for nxt, weight in graph[idx]:
                if prob[nxt] != 0:
                    continue
                heappush(pq, (p*weight, nxt) )
                
        return 0