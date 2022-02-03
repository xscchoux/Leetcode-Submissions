class Solution(object):
    def earliestAcq(self, logs, n):
        """
        :type logs: List[List[int]]
        :type n: int
        :rtype: int
        """
        parent = {i:i for i in range(n)}
        logs.sort(key = lambda x:x[0])
        count = n
        
        def find(x):
            if x != parent[x]:
                parent[x] = find(parent[x])
            return parent[x]
        
        def union(a,b):
            parent[find(a)] = find(b)
        
        for t, a, b in logs:
            if find(a) != find(b):
                union(a, b)
                count -= 1
                if count == 1:
                    return t

        return -1
        