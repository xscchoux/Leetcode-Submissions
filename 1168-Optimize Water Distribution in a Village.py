class Solution(object):
    def minCostToSupplyWater(self, n, wells, pipes):
        """
        :type n: int
        :type wells: List[int]
        :type pipes: List[List[int]]
        :rtype: int
        """
# Minimum Spanning Tree
# Time complexity: O((N+M)*log(N+M))
# Space complexity: O(M+N)
        parent = {i:i for i in range(0,n+1)}
        
        def find(ind):
            path = []
            while parent[ind] != ind:
                path.append(ind)
                ind = parent[ind]
                
            # path compression    
            for p in path:
                parent[p] = ind
            return ind
        
        def union(a, b):
            parentA = find(a)
            parentB = find(b)
            if parentA == parentB:
                return False
            else:
                parent[parentB] = parentA
                return True
        
        for i in range(len(wells)):
            pipes.append([0,i+1, wells[i]])
        res = 0
        pipes.sort(key = lambda x: x[2])
        
        for pipe in pipes:
            if union(pipe[0], pipe[1]):
                res += pipe[2]              
        return res