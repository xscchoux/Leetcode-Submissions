from collections import defaultdict
class Solution(object):
    def minimumCost(self, N, connections):
        """
        :type N: int
        :type connections: List[List[int]]
        :rtype: int
        """
        res = 0
        connections.sort(key = lambda x:x[2])
        self.parent = {i:i for i in range(1,N+1)}
        self.cities = N
        
        for start, end, cost in connections:
            if self.find(start) != self.find(end):
                self.union(start, end)
                res += cost
                
        if self.cities == 1:
            return res
        else:
            return -1
          
    def union(self, point_a, point_b):
        root_a = self.find(point_a)
        root_b = self.find(point_b)
        if root_a != root_b:
            self.parent[root_a] = root_b
            self.cities-=1
    
    def find(self, point):
        path = []
        while point != self.parent[point]:
            path.append(point)
            point = self.parent[point]
        for p in path:
            self.parent[p] = point
        return point