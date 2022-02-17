from heapq import *
class Solution:
    def maxProbability(self, n: int, edges: List[List[int]], succProb: List[float], start: int, end: int) -> float:
        graph = collections.defaultdict(list)
        for (u, v), p in zip(edges, succProb):
            graph[u].append([v, p])
            graph[v].append([u, p])

        prob = [0]*n
        visited = set()
        
        # Dijkstra's algorithm
        queue = [(-1, start)] #weight, index
        while queue:
            [currProb, currIdx] = heappop(queue)
            if currIdx == end:
                return -currProb
            currProb = -1*currProb

            for nxt, p in graph[currIdx]:
                if currProb*p > prob[nxt]:
                    prob[nxt] = currProb*p
                    heappush(queue, (-currProb*p, nxt))
 
        return prob[end]