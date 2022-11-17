from heapq import heappush, heappop
class Solution(object):
    def minCost(self, n, roads, appleCost, k):
        """
        :type n: int
        :type roads: List[List[int]]
        :type appleCost: List[int]
        :type k: int
        :rtype: List[int]
        """
        graph = collections.defaultdict(list)
        for u,v,w in roads:
            graph[u].append((v, w))
            graph[v].append((u, w))
        
        ans = []
        
        def djkstra(root):
            pathCost = [float('inf')]*n
            pq = [(0, root)]
            while pq:
                val, curr = heappop(pq)
                if pathCost[curr-1] <= val:
                    continue
                pathCost[curr-1] = val
                for nxt, weight in graph[curr]:
                    if val + weight*(1+k) < pathCost[nxt-1]:
                        heappush(pq, (val+weight*(1+k), nxt))

            return min(map(operator.add, pathCost, appleCost))
        
        for curr in range(1, n+1):
            num = djkstra(curr)
            ans.append(num)
            
        return ans