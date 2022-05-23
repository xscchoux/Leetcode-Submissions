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


# solution2, dfs+memoization

class Solution:
    def findMaxForm(self, strs: List[str], m: int, n: int) -> int:
        count = [(c.count("0"), c.count("1")) for c in strs]
        
        @cache
        def dfs(remainM, remainN, ind):
            if ind == len(strs):
                return 0
            
            minusM, minusN = count[ind]
            if remainM - minusM >= 0 and remainN - minusN >= 0:
                res = max( 1+ dfs(remainM-minusM, remainN-minusN, ind+1), dfs(remainM, remainN, ind+1) )
            else:
                res = dfs(remainM, remainN, ind+1)
            
            return res
        
        return dfs(m, n, 0)