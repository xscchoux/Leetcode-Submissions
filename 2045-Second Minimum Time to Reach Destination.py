from heapq import heappush, heappop
class Solution(object):
    def secondMinimum(self, n, edges, time, change):
        """
        :type n: int
        :type edges: List[List[int]]
        :type time: int
        :type change: int
        :rtype: int
        """
# Dijkstra's algorithm
        graph = collections.defaultdict(list)
        for u, v in edges:
            graph[u].append(v)
            graph[v].append(u)
        
        elapsed = [float('inf')]*(n+1)
        freq = [0]*(n+1)
        change2 = 2*change
        pq = [(0, 1)]  # time, vertex
        found = False
        
        while pq:
            currT, currV = heappop(pq)
            quo = currT//change
            if quo%2:
                currT += (change2 - currT%change2)
            for nxt in graph[currV]:
                if currT + time != elapsed[nxt] and freq[nxt] < 2:
                    if nxt == n:
                        if not found:
                            found = True
                        else:
                            return currT+time
                    freq[nxt] += 1
                    elapsed[nxt] = currT + time
                    heappush(pq, (currT+time,nxt) )
                    
# BFS (No need to use Dijkstra because all weights of the edges are equal)

        graph = collections.defaultdict(list)
        for u, v in edges:
            graph[u].append(v)
            graph[v].append(u)
        
        elapsed = [float('inf')]*(n+1)
        freq = [0]*(n+1)
        change2 = 2*change
        queue = collections.deque([(0, 1)])  # time, vertex
        found = False
        
        while queue:
            currT, currV = queue.popleft()
            quo = currT//change
            if quo%2:
                currT += (change2 - currT%change2)
            for nxt in graph[currV]:
                if currT + time != elapsed[nxt] and freq[nxt] < 2:
                    if nxt == n:
                        if not found:
                            found = True
                        else:
                            return currT+time
                    freq[nxt] += 1
                    elapsed[nxt] = currT + time
                    queue.append((currT+time,nxt))  