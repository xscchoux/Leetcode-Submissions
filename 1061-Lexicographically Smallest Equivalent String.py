class Solution:
    def smallestEquivalentString(self, s1: str, s2: str, baseStr: str) -> str:
        parent = {i:i for i in range(26)}
        
        def find(x):
            if parent[x] != x:
                parent[x] = find(parent[x])
            return parent[x]
        
        def union(a, b):
            pa, pb = find(a), find(b)
            if pa < pb:
                parent[pb] = pa
            else:
                parent[pa] = pb
        
        for a, b in zip(s1, s2):
            union(ord(a) - ord('a'), ord(b) - ord('a'))

        res = []
        
        for c in baseStr:
            ind = ord(c) - ord('a')
            res.append(chr(find(ind) + ord('a')))
        
        return "".join(res)