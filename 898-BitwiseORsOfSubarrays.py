class Solution(object):
    def subarrayBitwiseORs(self, A):
        """
        :type A: List[int]
        :rtype: int
        """

# DP
# Time complexity:O(n^2), Space complexity:O(n^2)
# dp[i][j] = A[i]|A[i+1]|...|A[j]
# dp[i][j-1]|A[j] = dp[i][j]

        n = len(A)
        res = set()
        dp = [[0]*n for _ in range(n)]
        for i in range(n):
            dp[i][i] = A[i]
            res.add(A[i])
        for l in range(2,n+1):
            for i in range(n-l+1):
                j = i+l-1
                dp[i][j] = dp[i][j-1]|A[j]
                res.add(dp[i][j])
        return len(res)
# DP              
# Time complexity:O(n^2), Space complexity:O(n^2) -> O(n)

        n = len(A)
        dp = [[0]*n for _ in range(n)]
        res = set()
        for i in range(n):
            dp[i] = A[i]
            res.add(A[i])
        for l in range(2,n+1):
            for i in range(n-l+1):
                dp[i] = dp[i]|A[i+l-1]
                res.add(dp[i])
        return len(res)

# DP 
# Time complexity: O(30n) (2^30 ~ 10^9) , Space complexity:O(30n)

        curr = set()
        res = set()
        
        for a in A:
            curr = {a|xx for xx in curr}|{a}
            res = res | curr
            
        return len(res)