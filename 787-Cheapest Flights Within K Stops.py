from collections import defaultdict, deque
class Solution(object):
    def findCheapestPrice(self, n, flights, src, dst, K):
        """
        :type n: int
        :type flights: List[List[int]]
        :type src: int
        :type dst: int
        :type K: int
        :rtype: int
        """
        graph = defaultdict(dict)
        for start, end, weight in flights:
            graph[start][end] = weight
            
        queue = deque()
        step = -1
        cost = 0
        queue.append((src, cost, step))
        ans = float('inf')
        
        while queue:
            for _ in range(len(queue)):
                cur, cost, step = queue.popleft()
                if step > K:
                    break
                if cur == dst:
                    ans = min(ans, cost)
                
                for nxt, weight in graph[cur].items():
                    if cost + weight < ans:
                        queue.append((nxt, cost+weight, step+1))
        
        return -1 if ans == float('inf') else ans