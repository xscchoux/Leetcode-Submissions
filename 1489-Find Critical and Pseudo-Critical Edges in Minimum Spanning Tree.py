class UnionFind:
    def __init__(self, n):
        self.children = dict()
        self.parent = {i:i for i in range(n)}
    
    def find(self, x):
        if x != self.parent[x]:
            self.parent[x] = self.find(self.parent[x])
        return self.parent[x]
    
    def union(self, a, b):
        pa, pb = self.find(a), self.find(b)
        if pa != pb:
            self.parent[pa] = pb

class Solution:
    def findCriticalAndPseudoCriticalEdges(self, n: int, edges: List[List[int]]) -> List[List[int]]:
        for ind, edge in enumerate(edges):
            edge.append(ind)
        # print(edges)
        edges.sort(key = lambda x:x[2])
        
        # kruskal's algo
        mstSum = 0
        uf = UnionFind(n)
        for s, e, w, ind in edges:
            if uf.find(s) != uf.find(e):
                uf.union(s, e)
                mstSum += w
        
        critical, pseudoCritical = [], []
        
        for s_outer, e_outer, w_outer, ind in edges:
            tot = 0
            # ignore this edge
            uf2 = UnionFind(n)
            for s, e, w, ind2 in edges:
                if ind == ind2:
                    continue
                if uf2.find(s) != uf2.find(e):
                    uf2.union(s, e)
                    tot += w
            if any(uf2.find(i) != uf2.find(0) for i in range(n)):
                critical.append(ind)
                continue
            if tot > mstSum:
                critical.append(ind)
                continue
            
            # force this edge to be used in MST
            tot = w_outer
            uf3 = UnionFind(n)
            uf3.union(s_outer, e_outer)
            for s, e, w, ind3 in edges:
                if ind == ind3:
                    continue
                if uf3.find(s) != uf3.find(e):
                    uf3.union(s, e)
                    tot += w
            if tot == mstSum:
                pseudoCritical.append(ind)
        
        return [critical, pseudoCritical]