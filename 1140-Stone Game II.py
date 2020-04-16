class Solution(object):
    def stoneGameII(self, piles):
        """
        :type piles: List[int]
        :rtype: int
        """
        n = len(piles)
        presum = [0]*(n+1)
        for i in range(n-1,-1,-1):
            presum[i] = presum[i+1] + piles[i]
        
        memo = {}
        def dfs(start, M):
            if (start, M) in memo:
                return memo[(start, M)]
            if start >= n:
                return 0
            if start + 2*M >= n:
                return presum[start]
            best = float('-inf')
            for i in range(start+1, min(start + 2*M+1,n+1)):
                best = max(best, presum[start] - presum[i] - dfs(i, max(i-start, M)))
            memo[(start, M)] = best
            return best
        
        return (presum[0] + dfs(0,1))//2