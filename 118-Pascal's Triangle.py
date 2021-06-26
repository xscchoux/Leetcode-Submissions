class Solution(object):
    def generate(self, numRows):
        """
        :type numRows: int
        :rtype: List[List[int]]
        """
        res = [[1]]
        dp = [1]
        
        for i in range(2, numRows+1):
            tmp = [1]*i
            for j in range(1, i-1):
                tmp[j] = dp[j] + dp[j-1]
            res.append(tmp)
            dp = tmp
            
        return res