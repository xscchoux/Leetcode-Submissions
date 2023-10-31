# Calculate least prime factor. If lpf[i] == i, i is a prime
MX = 100001
lpf = [0]*MX
for i in range(2, MX):
    if lpf[i] == 0:
        for j in range(i, MX, i):
            lpf[j] = i

class Solution:
    def countPaths(self, n: int, edges: List[List[int]]) -> int:
        parent = {i:i for i in range(1, n+1)}
        size = [1]*(n+1)
        count = [1]*(n+1) # count[i]: used when i is a prime number. count[i] is the size of neighbor non-prime composites + 1 (self)
        
        res = 0
        
        def find(x):
            if parent[x] != x:
                parent[x] = find(parent[x])
            return parent[x]
        
        def union(a, b):
            pa, pb = find(a), find(b)
            # connect smaller tree to larger tree
            if size[pa] < size[pb]:
                pa, pb = pb, pa
            parent[pb] = pa
            size[pa] += size[pb]
        
        for u, v in edges:
            if (lpf[u] != u) and (lpf[v] != v):
                union(u, v)
        
        for u, v in edges:
            if (lpf[u] == u)^(lpf[v] == v):
                if lpf[u] != u:
                    u, v = v, u
                # u is prime, v is a composite of non-prime
                res += count[u]*size[find(v)]
                count[u] += size[find(v)]
        
        return res


# Union-Find

MX = 100001
lpf = [0]*MX
for i in range(2, MX):
    if lpf[i] == 0:
        for j in range(i, MX, i):
            lpf[j] = i

class Solution:
    def countPaths(self, n: int, edges: List[List[int]]) -> int:
        # https://leetcode.com/problems/count-valid-paths-in-a-tree/discuss/4082791/Python3-DSU
        parent = {i:i for i in range(1, n+1)}
        res = 0
        size = [1]*(n+1)
        
        def find(x):
            if x != parent[x]:
                parent[x] = find(parent[x])
            return parent[x]
        
        def union(a, b):
            pa, pb = find(a), find(b)
            if size[pa] < size[pb]:
                pa, pb = pb, pa
            parent[pb] = pa
            size[pa] += size[pb]
        
        count = [1]*(n+1) # count[i] is used when i is prime. count[i] is the total number in neighboring non-prime composite + 1
        
        for u,v in edges:
            if lpf[u] != u and lpf[v] != v:
                union(u, v)
        
        for u, v in edges:
            if (lpf[u] == u)^(lpf[v] == v):
                if lpf[u] != u:
                    u, v = v, u
                # u is a prime number, size[find(v)] is a composite of non-prime numbers
                res += count[u]*size[find(v)]
                count[u] += size[find(v)]
        
        return res