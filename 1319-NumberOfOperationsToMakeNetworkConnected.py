class Solution(object):
    def makeConnected(self, n, connections):
        """
        :type n: int
        :type connections: List[List[int]]
        :rtype: int
        """
        if len(connections) < n - 1:
            return -1
        
        self.parent = {i:i for i in range(n)}
        self.nCC = n
        canMove = 0
        for p1, p2 in connections:
            canMove += self.union(p1,p2)
        return -1 if self.nCC-1 > canMove else self.nCC-1
    
    def union(self, pa, pb):
        ra = self.find(pa)
        rb = self.find(pb)
        if ra != rb:
            self.parent[ra] = rb
            self.nCC-=1
            return 0
        return 1
            
    def find(self, point):
        path = []
        while point != self.parent[point]:
            path.append(point)
            point = self.parent[point]
        for p in path:
            self.parent[p] = point
        return point