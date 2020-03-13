class Solution(object):
    def maxSubArray(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
# time complexity: O(n), space complexity: O(n)

        dp = [0]*len(nums)
        dp[0] = nums[0]
        for i in range(1, len(nums)):
            dp[i] = max(dp[i-1]+nums[i],nums[i])
        return max(dp)
    
# time complexity: O(n), space complexity: O(1)

        localmax = nums[0]
        globalmax = nums[0]
        
        for i in range(1,len(nums)):
            localmax = max(localmax+nums[i], nums[i])
            globalmax = max(localmax, globalmax)
                
        return globalmax
    
# possible followup (print out the subarray)

        localmax = nums[0]
        globalmax = nums[0]
        localbegin, localend = 0, 0
        globalbegin, globalend = 0, 0
        for i in range(1,len(nums)):
            if localmax + nums[i] >= nums[i]:
                localmax += nums[i]
                localend += 1
            else:
                localmax = nums[i]
                localbegin, localend = i, i
            if localmax > globalmax:
                globalmax = localmax
                globalbegin, globalend = localbegin, localend
                
        print(nums[globalbegin:globalend+1])
        return sum(nums[globalbegin:globalend+1])