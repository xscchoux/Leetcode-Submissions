class Solution(object):
    def missingElement(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
        
# O(n)
        for i in range(len(nums)-1):
            diff = 0
            if nums[i] + 1 < nums[i+1]:
                diff += nums[i+1] - nums[i] - 1
            if k - diff <=0:
                return nums[i] + k
            else:
                k-= diff
            
        if k>0:
            return nums[-1]+k
            
# binary search O(logN)
        missing = lambda idx: nums[idx] - nums[0] - idx
    
        n = len(nums)
        
        if k>missing(n-1):
            return nums[-1] + k - missing(n-1)
        left, right = 0 , len(nums)-1
        while left+1<right:
            mid = left + (right-left)//2
            
            if missing(mid) < k:
                left = mid
            else:
                right = mid
                
        return nums[left] + k - missing(left)