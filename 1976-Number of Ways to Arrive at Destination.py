from heapq import heappush, heappop
class Solution(object):
    def countPaths(self, n, roads):
        """
        :type n: int
        :type roads: List[List[int]]
        :rtype: int
        """
        count = 0
        kMod = 1000000007
        graph = collections.defaultdict(list)
        for start, end, weight in roads:
            graph[start].append([end, weight])
            graph[end].append([start, weight])
        
        dist = [float('inf')]*n
        paths = [1]*n
        pq = [(0, 0)]
        
        while pq:
            distance, node = heappop(pq)
            if node == n-1:
                return paths[n-1]%kMod
            for nxt, weight in graph[node]:
                if distance + weight == dist[nxt]:
                    paths[nxt] += paths[node]
                    continue
                
                elif distance + weight < dist[nxt]:
                    dist[nxt] = distance + weight
                    paths[nxt] = paths[node]
                    heappush(pq, (dist[nxt], nxt))            
