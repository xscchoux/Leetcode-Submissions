from heapq import heappush, heappop
class Graph:

    def __init__(self, n: int, edges: List[List[int]]):
        self.hmap = defaultdict(list)
        for edge in edges:
            self.hmap[edge[0]].append((edge[1], edge[2]))
        self.n = n
        
    def addEdge(self, edge: List[int]) -> None:
        self.hmap[edge[0]].append((edge[1], edge[2]))

    def shortestPath(self, node1: int, node2: int) -> int:
        pq = []
        pq.append((0, node1))
        dist = [float('inf')]*self.n
        
        while pq:
            d, node = heappop(pq)
            if d > dist[node]:
                continue
            if node == node2:
                return d
            dist[node] = d
            for nxt, dd in self.hmap[node]:
                if d + dd < dist[nxt]:
                    dist[nxt] = d + dd
                    heappush(pq, (d+dd, nxt))
    
        return -1

# Your Graph object will be instantiated and called as such:
# obj = Graph(n, edges)
# obj.addEdge(edge)
# param_2 = obj.shortestPath(node1,node2)