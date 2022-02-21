from heapq import heappush, heappop
class Solution(object):
    def minimumCost(self, n, highways, discounts):
        """
        :type n: int
        :type highways: List[List[int]]
        :type discounts: int
        :rtype: int
        """
# https://leetcode.com/problems/minimum-cost-to-reach-city-with-discounts/discuss/1617341/Python3-Dijkstra-Beats-100-Time-Memory-commented-readable
        graph = collections.defaultdict(list)

        for start, end, cost in highways:
            graph[start].append((end, cost))
            graph[end].append((start, cost))
        
        visited = dict()  # city index : discount remain
        
        queue = [(0, 0, discounts)] # distance from 0, current city, discount remain
        
        while queue:
            currDist, currCity, remain = heappop(queue)
            if currCity in visited and remain <= visited[currCity]:
                continue
            visited[currCity] = remain
            if currCity == n-1:
                return currDist
            for nxt, weight in graph[currCity]:
                if remain > 0:
                    heappush(queue,(currDist + weight//2, nxt, remain-1))
                heappush(queue, (currDist + weight, nxt, remain))
                
        return -1