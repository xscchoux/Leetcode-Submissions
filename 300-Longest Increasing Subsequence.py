class Solution(object):
    def lengthOfLIS(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
# DP, O(N^2)
        N = len(nums)
        dp = [1]*N
        res = 1
        for i in range(1, N):
            for j in range(i):
                if nums[i] > nums[j]:
                    dp[i] = max(dp[i], dp[j] + 1)
            res = max(res, dp[i])
        
        return res

# build a sequence, O(NlogN)
        
        res = []
        for num in nums:
            if not res or num > res[-1]:
                res.append(num)
            else:
                l, r = 0, len(res) - 1
                while l + 1 < r:
                    mid = l + (r-l)//2
                    if res[mid] < num:
                        l = mid
                    else:
                        r = mid
                if res[l] >= num:
                    res[l] = num
                else:
                    res[r] = num     
        return len(res)