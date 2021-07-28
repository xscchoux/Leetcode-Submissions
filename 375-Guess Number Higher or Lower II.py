class Solution(object):
    def getMoneyAmount(self, n):
        """
        :type n: int
        :rtype: int
        """
        
# Top down DP
# Time complexity: O(n^3), Space complexity:O(n^2)
        memo = dict()
        
        def helper(left, right):
            if left >= right:
                return 0
            if (left, right) in memo:
                return memo[(left, right)]
            
            res = float('inf')
            for i in range(left, right+1):
                res = min(res, i + max( helper(left, i-1), helper(i+1, right) ))
            memo[(left, right)] = res
            return res
        
        return helper(1, n)
    
# bottom up DP
# Time complexity: O(n^3), Space complexity:O(n^2)
        dp = [[0]*(n+2) for _ in range(n+2)]
    
        for right in range(1, n+1):
            for left in range(right-1,0,-1):
                dp[left][right] = min( [ k + max( dp[left][k-1], dp[k+1][right] ) for k in range(left, right+1)]) 
        return dp[1][n]
        