class Solution(object):
    def champagneTower(self, poured, query_row, query_glass):
        """
        :type poured: int
        :type query_row: int
        :type query_glass: int
        :rtype: float
        """
        dp = [[0]*(r+1) for r in range(query_row+2)]
        dp[0][0] = poured
        
        for r in range(query_row+1):
            for c in range(r+1):
                nxt = (dp[r][c] - 1)/float(2)
                if nxt > 0:
                    dp[r+1][c] += nxt
                    dp[r+1][c+1] += nxt

        return min(1, dp[query_row][query_glass])