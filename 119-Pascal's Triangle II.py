class Solution(object):
    def getRow(self, rowIndex):
        """
        :type rowIndex: int
        :rtype: List[int]
        """
        if rowIndex == 0:
            return [1]
        
        dp = [1]
        for i in range(1, rowIndex+1):
            tmp = [1]*(i+1)
            for j in range(1, i):
                tmp[j] = dp[j-1] + dp[j]
            dp = tmp
        
        return dp