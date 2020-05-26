class Solution(object):
    def maxUncrossedLines(self, A, B):
        """
        :type A: List[int]
        :type B: List[int]
        :rtype: int
        """
        
# time: O(n^2)
# space: O(n^2)

        lenA = len(A)
        lenB = len(B)
        
        dp = [[0]*(lenA+1) for _ in range(lenB+1)]
        
        for i in range(1, lenB+1):
            for j in range(1, lenA+1):
                if A[j-1] == B[i-1]:
                    dp[i][j] = dp[i-1][j-1]+1
                else:
                    dp[i][j] = max(dp[i][j-1], dp[i-1][j])
        return dp[-1][-1]


# time: O(n^2)
# space: O(n)

        lenA = len(A)
        lenB = len(B)
        
        dp = [[0]*(lenA+1) for _ in range(2)]
        
        for i in range(1, lenB+1):
            for j in range(1, lenA+1):
                if A[j-1] == B[i-1]:
                    dp[i%2][j] = dp[(i-1)%2][j-1]+1
                else:
                    dp[i%2][j] = max(dp[i%2][j-1], dp[(i-1)%2][j])
        print(dp)
        return dp[len(B)%2][-1]