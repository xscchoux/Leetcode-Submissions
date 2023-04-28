class Solution:
    def numSimilarGroups(self, strs: List[str]) -> int:
        parent = {i:i for i in range(len(strs))}
        
        def isSimilar(a, b):
            cnt = 0
            for x, y in zip(a, b):
                if x != y:
                    cnt += 1
                if cnt > 2:
                    return False
            return cnt == 0 or cnt == 2
        
        def find(x):
            if x != parent[x]:
                parent[x] = find(parent[x])
            return parent[x]
        
        def union(a, b):
            pa, pb = find(a), find(b)
            if pa != pb:
                parent[pa] = pb
        
        for i in range(len(strs)-1):
            for j in range(i+1, len(strs)):
                if find(i) != find(j) and isSimilar(strs[i], strs[j]):
                    union(i, j)
        
        return len(set([find(i) for i in range(len(strs))]))