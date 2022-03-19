from heapq import heappush, heappop
class Solution(object):
    def minimumWeight(self, n, edges, src1, src2, dest):
        """
        :type n: int
        :type edges: List[List[int]]
        :type src1: int
        :type src2: int
        :type dest: int
        :rtype: int
        """
        graph, rgraph = collections.defaultdict(list), collections.defaultdict(list)
        
        for u, v, w in edges:
            graph[u].append((v, w))
            rgraph[v].append((u, w))
        
        def dijkstra(start, graph):
            res = [float('inf')]*n
            res[start] = 0
            pq = [(0, start)]
            
            while pq:
                dist, curr = heappop(pq)
                
                # very important pruning
                if dist > res[curr]:
                    continue

                for nxt, weight in graph[curr]:
                    if dist + weight < res[nxt]:
                        res[nxt] = dist + weight
                        heappush(pq, (dist+weight, nxt))
            return res
        
        arr1 = dijkstra(src1, graph)
        arr2 = dijkstra(src2, graph)
        dest = dijkstra(dest, rgraph)
        
        ans = float('inf')
        for i in range(n):
            ans = min(ans, arr1[i]+arr2[i]+dest[i])
        
        return -1 if ans == float('inf') else ans