class Solution:
    def maxValueOfCoins(self, piles: List[List[int]], k: int) -> int:
        
        N = len(piles)
        
        @cache
        def dfs(ind, remainK):
            if ind == N:
                if remainK == 0:
                    return 0
                else:
                    return float('-inf')
            ans = dfs(ind + 1, remainK)
            curr = 0
            for j in range(min(remainK, len(piles[ind]))):
                curr += piles[ind][j]
                ans = max(ans, curr + dfs(ind+1, remainK-j-1))
            return ans
        
        return dfs(0, k)