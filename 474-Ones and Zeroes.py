class Solution(object):
    def findMaxForm(self, strs, m, n):
        """
        :type strs: List[str]
        :type m: int
        :type n: int
        :rtype: int
        """
# knapsack problem
# Time complexity: O(len(strs)*m*n), Space complexity:O(m*n)

        dp = [[0]*(n+1) for _ in range(m+1)]
    
        for string in strs:
            ones = zeros = 0
            for char in string:
                if char=='1':
                    ones += 1
                else:
                    zeros += 1

            for i in range(m, zeros-1, -1):
                for j in range(n, ones-1, -1):
                    dp[i][j] = max(dp[i][j], dp[i-zeros][j-ones]+1)

        return dp[-1][-1] 