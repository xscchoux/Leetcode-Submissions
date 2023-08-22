class Solution:
    def maximizeTheProfit(self, n: int, offers: List[List[int]]) -> int:
# My solution
        offers.sort(key = lambda x:x[1])        
        dp = [0]*(n+1)
        idx = 0

        for i in range(1, n+1):
            dp[i] = dp[i-1]
            while idx < len(offers) and offers[idx][1] <= i-1:
                if offers[idx][1] < i-1:
                    idx += 1
                else:
                    dp[i] = max(dp[i], offers[idx][2] + dp[offers[idx][0]])
                    idx += 1

        return dp[-1]

# Without sorting, brilliant
# https://leetcode.com/problems/maximize-the-profit-as-the-salesman/discuss/3934188/JavaC%2B%2BPython-DP-O(n-%2B-m)
        dp = [0]*(n+1)
        memo = [[] for _ in range(n)]
        
        for s, e, w in offers:
            memo[e].append((s, w))
            
        for i in range(1, n+1):
            dp[i] = dp[i-1]
            for s, w in memo[i-1]:
                dp[i] = max(dp[i], dp[s] + w)

        return dp[-1]
            