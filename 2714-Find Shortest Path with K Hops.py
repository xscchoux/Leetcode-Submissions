from heapq import heappush, heappop
class Solution:
    def shortestPathWithHops(self, n: int, edges: List[List[int]], s: int, d: int, k: int) -> int:
        graph = defaultdict(list)
        for u, v, w in edges:
            graph[u].append((v, w))
            graph[v].append((u, w))
            
        pq = [(0, s, 0)]   # distance, index of node, hops
        distances = defaultdict(lambda:float('inf'))
        res = float('inf')
        
        while pq:
            dist, node, hop = heappop(pq)
            if node == d:
                res = min(res, dist)
            if distances[(node, hop)] != float('inf'):
                continue

            for nxt, weight in graph[node]:
                if dist + weight < distances[(nxt, hop)]:
                    distances[(node, hop)] = dist + weight
                    heappush(pq, (dist+weight, nxt, hop))
                if hop < k and dist < distances[(nxt, hop+1)]:
                    distances[(node, hop+1)] = dist
                    heappush(pq, (dist, nxt, hop+1))
        return res