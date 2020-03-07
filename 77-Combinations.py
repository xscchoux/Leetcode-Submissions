class Solution(object):
    def combine(self, n, k):
        """
        :type n: int
        :type k: int
        :rtype: List[List[int]]
        """
# DFS O(k*C(n,k))
        res = []
        def dfs(start, k, val):
            if k==0:
                res.append(val)
                return
            for i in range(start, n+1):
                dfs(i+1, k-1, val+[i])
        dfs(1, k, [])
        return res
# Much faster         
        res = []
        def dfs(start, k, val):
            if k==0:
                res.append(val)
                return
            for i in range(start, n+1):
                if n-i+1 < k:            # pruning
                    break
                dfs(i+1, k-1, val+[i])
        dfs(1, k, [])
        return res