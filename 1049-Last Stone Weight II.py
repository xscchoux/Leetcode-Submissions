class Solution(object):
    def lastStoneWeightII(self, stones):
        """
        :type stones: List[int]
        :rtype: int
        """
# knapsack
        summ = sum(stones)
        upperbound = summ//2
        dp = [False]*(upperbound+1)
        dp[0] = True
        
        for stone in stones:
            for i in range(len(dp)-1, 0, -1):
                if i-stone < 0:
                    break
                if dp[i-stone]:
                    dp[i] = True
            if dp[-1]:
                return summ%2
        
        for i in range(len(dp)-1, -1, -1):
            if dp[i]:
                return summ-2*i