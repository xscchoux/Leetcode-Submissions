class Solution:
    def makeConnected(self, n: int, connections: List[List[int]]) -> int:
        if n - 1 > len(connections):
            return -1
        
        parent = {i:i for i in range(n)}
        
        def find(x):
            if parent[x] != x:
                parent[x] = find(parent[x])
            return parent[x]
        
        def union(a, b):
            nonlocal n
            pa, pb = find(a), find(b)
            if pa != pb:
                n -= 1
                parent[pa] = pb
            
        for u, v in connections:
            union(u, v)
            
        return n - 1