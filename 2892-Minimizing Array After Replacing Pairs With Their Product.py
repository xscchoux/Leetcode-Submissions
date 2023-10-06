class Solution:
    def minArrayLength(self, nums: List[int], k: int) -> int:
        # greedy, put as many items as possible in a box of volumn k
        
        if 0 in nums:  # edge case
            return 1
        
        res = 1
        prefix = nums[0]
        
        for i in range(1, len(nums)):
            if prefix*nums[i] > k:
                prefix = nums[i]
                res += 1
            else:
                prefix = prefix*nums[i]
        
        return res