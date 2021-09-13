from heapq import heappush, heappop
from collections import defaultdict
class Solution(object):
    def reachableNodes(self, edges, maxMoves, n):
        """
        :type edges: List[List[int]]
        :type maxMoves: int
        :type n: int
        :rtype: int
        """
        graph = defaultdict(list)
        
        for u, v, cnt in edges:
            graph[u].append((v, cnt+1))
            graph[v].append((u, cnt+1))
            
        pq = []
        heappush(pq, (0, 0))    # (distance from the origin, node number)
        visited = set()
        dist = [float('inf')]*n
        dist[0] = 0
        
        while pq:
            distance, node = heappop(pq)
            visited.add(node)
            
            for nxt, steps in graph[node]:
                if nxt not in visited:
                    if steps + distance < dist[nxt]:
                        dist[nxt] = distance + steps
                        heappush(pq, (distance + steps, nxt))
        
        res = 0
        
        for d in dist:
            if d<=maxMoves:
                res += 1
        
        for u, v, cnt in edges:
            cntU = max(maxMoves-dist[u], 0)
            cntV = max(maxMoves-dist[v], 0)
            res += min(cntU+cntV, cnt)
            
        return res