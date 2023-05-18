class Solution:
    def maximumOr(self, nums: List[int], k: int) -> int:
        
# prefix and suffix array
        res = 0
        prefixOR = [0]*(len(nums)+1)
        suffixOR = [0]*(len(nums)+1)
        
        for i in range(len(nums)):
            prefixOR[i+1] = nums[i] | prefixOR[i]
        
        for i in range(len(nums)-1, -1, -1):
            suffixOR[i] = nums[i] | suffixOR[i+1]
        
        for i in range(len(nums)):
            res = max(res, (prefixOR[i]| (nums[i]<<k) )| suffixOR[i+1] )
        
        return res
        
# smart bitwise manipulation
        curr = 0
        saved = 0  # save bits that appear more than once
        res = 0
        
        for num in nums:
            saved = saved | num&curr   # don't need parenthesis for num&curr 
            curr = curr | num
            
        for num in nums:
            res = max(res, saved | curr^num | num << k)    
        
        return res