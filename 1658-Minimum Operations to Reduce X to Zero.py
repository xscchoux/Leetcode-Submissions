class Solution(object):
    def minOperations(self, nums, x):
        """
        :type nums: List[int]
        :type x: int
        :rtype: int
        """
# sliding window
        summ = sum(nums)
        if summ < x:
            return -1
        
        curr = 0
        res = -1
        left = 0
        for i in range(len(nums)):
            curr += nums[i]
            while curr > summ-x:
                curr -= nums[left]
                left += 1
            if curr == summ-x:
                res = max(res, i-left+1 )
                
        return len(nums) - res if res!=-1 else -1