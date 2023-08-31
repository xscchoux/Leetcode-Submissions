class Solution(object):
    def findNumberOfLIS(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        N = len(nums)
        count = [1]*N  # number of longest subsequence that ends at the ith element
        maxLen = [1]*N # length of longest subsequence that ends at the ith element
        
        for i in range(1, len(nums)):
            tmpCount = tmpLen = 1
            for j in range(i):
                if nums[j] < nums[i]:
                    if maxLen[j] + 1 > tmpLen:
                        tmpLen = maxLen[j] + 1
                        tmpCount = count[j]
                    elif maxLen[j] + 1 == tmpLen:
                        tmpCount += count[j]
            count[i] = tmpCount
            maxLen[i] = tmpLen
        
        res = 0
        longest = 1
        
        for i in range(len(maxLen)):
            if maxLen[i] > longest:
                res = count[i]
                longest = maxLen[i]
            elif maxLen[i] == longest:
                res += count[i]
                
        return res



# Redo. This solution is better
        N = len(nums)
        dp = [1]*N    # max length of the subsequence that ends at index i
        count = [1]*N # number of subsequences with maxLength that ends at index i
        
        for i in range(N):
            for j in range(i):
                if nums[i] > nums[j]:
                    if dp[j] + 1 > dp[i]:
                        dp[i] = dp[j] + 1
                        count[i] = count[j]
                    elif dp[j] + 1 == dp[i]:
                        count[i] += count[j]
      
        maxLength = max(dp)
        res = 0
        
        for i in range(N):
            if dp[i] == maxLength:
                res += count[i]
        
        return res