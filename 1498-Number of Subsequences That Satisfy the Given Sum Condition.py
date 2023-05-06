class Solution:
    def numSubseq(self, nums: List[int], target: int) -> int:
        
# sort + binary search
        nums.sort()
        kMod = 1000000007
        res = 0
        
        for i in range(len(nums)):
            if nums[i]*2 > target:
                break
            ind = bisect_left(nums, target-nums[i]+1)
            res = (res + pow(2, ind-i-1, kMod))%kMod
        
        return res
    
# sort + two pointer
        nums.sort()
        j = len(nums) - 1
        kMod = 1000000007
        res = 0
        
        for i in range(len(nums)):
            if nums[i]*2 > target:
                break
            while nums[i] + nums[j] > target:
                j -= 1
            res = (res + pow(2, j-i, kMod))%kMod
            
        return res