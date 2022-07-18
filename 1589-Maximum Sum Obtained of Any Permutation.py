class Solution(object):
    def maxSumRangeQuery(self, nums, requests):
        """
        :type nums: List[int]
        :type requests: List[List[int]]
        :rtype: int
        """
        tot = [0]*(len(nums)+1)
        
        for u, v in requests:
            tot[u] += 1
            tot[v+1] -= 1
        
        for i in range(1, len(tot)):
            tot[i] = tot[i] + tot[i-1]
            
        tot.sort(reverse=True)
        nums.sort(reverse=True)
        
        res = 0
        for i in range(len(nums)):
            res = (res + tot[i]*nums[i])%1000000007
            
        return res