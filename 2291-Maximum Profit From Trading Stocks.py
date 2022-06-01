class Solution(object):
    def maximumProfit(self, present, future, budget):
        """
        :type present: List[int]
        :type future: List[int]
        :type budget: int
        :rtype: int
        """
        N = len(present)
        dp = [0]*(budget+1)

        for j in range(N):
            diff = future[j] - present[j]
            if diff <= 0:
                continue
            for i in range(budget, present[j]-1, -1):
                dp[i] = max(dp[i], dp[i-present[j]] + diff)

        return dp[-1]