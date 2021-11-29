class Solution(object):
    def findAllPeople(self, n, meetings, firstPerson):
        """
        :type n: int
        :type meetings: List[List[int]]
        :type firstPerson: int
        :rtype: List[int]
        """
        parent = {i: i for i in range(n)}
        
        res = set([0, firstPerson])
        parent[firstPerson] = 0
        
        def find(x):
            if x != parent[x]:
                parent[x] = find(parent[x])
            return parent[x]
        
        def union(a, b):
            pa, pb = find(a), find(b)
            if pa!=pb:
                parent[pa] = pb
        
        hmap = collections.defaultdict(list)
        
        for a, b, time in meetings:
            hmap[time].append((a, b))
            
        for time in sorted(hmap.keys()):
            arr = hmap[time]
            for x, y in arr:
                union(x, y)
            for x, y in arr:
                if find(x) == find(0):
                    res.add(x)
                    res.add(y)
                else:
                    parent[x] = x
                    parent[y] = y

        return list(res)