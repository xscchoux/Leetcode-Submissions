class Solution(object):
    def wiggleMaxLength(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
# O(n^2)
# dp[end in small:0 or end in large:1][current index] = length by far

        N = len(nums)
        dp = [[1]*N for _ in range(2)]
        res = 1
        
        for i in range(1, N):
            tmpLarge = 1
            tmpSmall = 1
            for j in range(i):
                if nums[i] > nums[j]:
                    dp[1][i] = max(dp[1][i], 1+dp[0][j])
                elif nums[i] < nums[j]:
                    dp[0][i] = max(dp[0][i], 1+dp[1][j])
            res = max(res, max(dp[1][i], dp[0][i]))
        
        return res
            
# up:longest wiggle subsequence at an up position
# down:longest wiggle subsequence at a down position
        up = down = 1
        for i in range(1, len(nums)):
            if nums[i] > nums[i-1]:
                up = down + 1
            elif nums[i] < nums[i-1]:
                down = up + 1
        
        return max(up, down)