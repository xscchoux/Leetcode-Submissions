class Solution(object):
    def friendRequests(self, n, restrictions, requests):
        """
        :type n: int
        :type restrictions: List[List[int]]
        :type requests: List[List[int]]
        :rtype: List[bool]
        """
        parent = {i:i for i in range(n+1)}
        res = []
        
        def find(x):
            if parent[x] != x:
                parent[x] = find(parent[x])                
            return parent[x]
        
        def union(a, b):
            pa = find(a)
            pb = find(b)
            if pa != pb:
                parent[pa] = pb
            
        for i in range(len(requests)):
            u, v = requests[i]
            pu, pv = find(u), find(v)
            bad = True
            for x, y in restrictions:
                px, py = find(x), find(y)
                if set([px, py]) == set([pu, pv]):
                    bad = False
                    break
                    
            res.append(bad)
            
            if bad:
                union(pu, pv)
                
        return res