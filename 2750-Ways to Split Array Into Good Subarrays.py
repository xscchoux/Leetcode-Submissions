class Solution:
    def numberOfGoodSubarraySplits(self, nums: List[int]) -> int:
        if any(nums):
            nums = [i for i, num in enumerate(nums) if num]
            res = 1
            for pos1, pos2 in zip(nums, nums[1:]):
                diff = pos2 - pos1
                res = (res*diff)%(10**9+7)
            return res
        else:
            return 0