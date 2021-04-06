class Solution(object):
    def PredictTheWinner(self, nums):
        """
        :type nums: List[int]
        :rtype: bool
        """
# DFS + memoization
# Time complexity:O(N^2), Space complexity:O(N^2)

        memo = dict()
        
        def dfs(start,end):
            if (start, end) in memo:
                return memo[(start, end)]
            if start == end:
                return nums[start]
            memo[(start, end)] = max( nums[start] - dfs(start+1, end), nums[end] - dfs(start, end-1) )
            return memo[(start, end)]
        
        if dfs(0, len(nums)-1) >= 0:
            return True
        else:
            return False

# DP
# Time complexity:O(N^2), Space complexity:O(N^2)

        N = len(nums)
        dp = [[0]*N for _ in range(N)]
        
        for i in range(len(nums)):
            dp[i][i] = nums[i]
        
        for length in range(2, N+1):
            for start in range(N-length+1):
                end = start+length-1
                dp[start][end] = max(nums[start] - dp[start+1][end], nums[end] - dp[start][end-1])
                
        return dp[0][N-1] >= 0

# DP
# Time complexity:O(N^2), Space complexity:O(N)

        dp = nums[:]
        N = len(nums)
        
        for length in range(2, N+1):
            for end in range(N-1, length-2,-1):
                start = end-length+1
                dp[end] = max(nums[end]-dp[end-1], nums[start]-dp[end])
        return dp[-1] >= 0