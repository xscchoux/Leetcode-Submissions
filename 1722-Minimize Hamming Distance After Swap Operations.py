class Solution(object):
    def minimumHammingDistance(self, source, target, allowedSwaps):
        """
        :type source: List[int]
        :type target: List[int]
        :type allowedSwaps: List[List[int]]
        :rtype: int
        """
        # https://leetcode.com/problems/minimize-hamming-distance-after-swap-operations/discuss/1127721/Python-or-Simple-or-Union-Find
        N = len(source)
        parent = {i:i for i in range(N)}
        
        def union(x, y):
            px, py = find(x), find(y)
            if px != py:
                parent[px] = py
            
        def find(x):
            if x != parent[x]:
                parent[x] = find(parent[x])
            return parent[x]
        
        for x, y in allowedSwaps:
            union(x, y)
        
        hmap = collections.defaultdict(collections.Counter)
        for ind, s in enumerate(source):
            root = find(ind)
            hmap[root][s] += 1
        
        res = 0
        for i in range(len(source)):
            t = target[i]
            root = find(i)
            if hmap[root][t] > 0:
                hmap[root][t] -= 1
            else:
                res += 1
                
        return res