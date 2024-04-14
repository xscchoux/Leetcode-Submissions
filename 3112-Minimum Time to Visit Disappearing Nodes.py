from heapq import *
class Solution:
    def minimumTime(self, n: int, edges: List[List[int]], disappear: List[int]) -> List[int]:
        pq = [(0, 0)]
        graph = defaultdict(list)
        for u, v, w in edges:
            if u == v:
                continue
            graph[u].append((v, w))
            graph[v].append((u, w))
        
        res = [-1]*n
        
        while pq:
            time, node = heappop(pq)
            if res[node] != -1:
                continue
            res[node] = time
            for nxt, weight in graph[node]:
                if time + weight >= disappear[nxt]:
                    continue
                heappush(pq, (time+weight, nxt))
        
        return res