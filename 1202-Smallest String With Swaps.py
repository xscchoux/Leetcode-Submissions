class Solution(object):
    def smallestStringWithSwaps(self, s, pairs):
        """
        :type s: str
        :type pairs: List[List[int]]
        :rtype: str
        """
        parents = {i:i for i in range(len(s))}
        
        def find(x):
            if parents[x] != x:
                parents[x] = find(parents[x]) 
            return parents[x]
        
        def union(a, b):
            pa, pb = find(a), find(b)
            parents[pa] = pb
            
        for a, b in pairs:
            union(a, b)
        
        hmap = collections.defaultdict(list)
        for i in range(len(s)):
            hmap[find(i)].append(s[i])
            
        for k, v in hmap.items():
            hmap[k] = sorted(v, reverse=True)
            
        res = []
        for i in range(len(s)):
            res.append(hmap[find(i)].pop())
            
        return "".join(res)