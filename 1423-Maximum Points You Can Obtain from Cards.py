class Solution(object):
    def maxScore(self, cardPoints, k):
        """
        :type cardPoints: List[int]
        :type k: int
        :rtype: int
        """
# DFS (TLE)
# Time complexity: O(n*k)
        memo = {}
        
        def dfs(start, end, k):
            if k == 0:
                return 0
            if (start, end) in memo:
                # print("here", start, end)
                return memo[(start, end)]
            
            res = max(cardPoints[start] + dfs(start+1, end, k-1), cardPoints[end] + dfs(start, end-1, k-1))
            memo[(start, end)] = res
            return res
        
        res = dfs( 0, len(cardPoints)-1, k)
        return res

# sliding window
# Time complexity: O(n)
        N = len(cardPoints)
        tmp = sum(cardPoints[:N-k])
        res = tmp
        for i in range(N-k, len(cardPoints)):
            tmp = tmp + cardPoints[i] - cardPoints[i-N+k]
            res = min(res, tmp)
            
        return sum(cardPoints) - res
    