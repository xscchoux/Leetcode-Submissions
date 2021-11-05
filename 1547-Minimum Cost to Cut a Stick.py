class Solution(object):
    def minCost(self, n, cuts):
        """
        :type n: int
        :type cuts: List[int]
        :rtype: int
        """
        
# Top-down, O(N^3)
        cuts = [0] + cuts + [n]
        cuts.sort()
        N = len(cuts) - 1
        memo = dict()
        
        def dfs(startIdx, endIdx):
            if startIdx + 1 == endIdx:
                return 0
            if (startIdx, endIdx) in memo:
                return memo[(startIdx, endIdx)]
            res = float('inf')
            for i in range(startIdx+1, endIdx):
                res = min(res, dfs(startIdx, i) + dfs(i, endIdx) + cuts[endIdx] - cuts[startIdx] )
            memo[(startIdx, endIdx)] = res
            return res
        
        res = dfs(0, N)
        return res