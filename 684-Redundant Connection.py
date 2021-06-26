class Solution(object):
    def findRedundantConnection(self, edges):
        """
        :type edges: List[List[int]]
        :rtype: List[int]
        """

# with only path compression, without union by rank

        N = len(edges)
        parent = {i:i for i in range(1, N+1)}
        
        def find(x):
            path = []
            while parent[x] != x:
                path.append(x)
                x = parent[x]
            for xx in path:
                parent[xx] = x
            return x
            
        def union(u, v):
            rootU = find(u)
            rootV = find(v)
            if rootU == rootV:
                return False
            parent[rootV] = rootU
            return True
            
        for u, v in edges:
            if not union(u, v):
                return [u, v]
            
            
# with path compression and union by rank
        N = len(edges)
        parent = {i:i for i in range(1, N+1)}
        rank = [1]*(N+1)
        
        def find(x):
            path = []
            while parent[x] != x:
                path.append(x)
                x = parent[x]
            for xx in path:
                parent[xx] = x
            return x
            
        def union(u, v):
            rootU = find(u)
            rootV = find(v)
            if rootU == rootV:
                return False
            
            if rank[rootU] > rank[rootV]:
                parent[rootV] = rootU
            elif rank[rootU] < rank[rootV]:
                parent[rootU] = rootV                
            else:
                rank[rootU] += 1
                parent[rootV] = rootU
            return True
            
        for u, v in edges:
            if not union(u, v):
                return [u, v]
        