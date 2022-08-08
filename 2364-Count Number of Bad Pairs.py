class Solution:
    def countBadPairs(self, nums: List[int]) -> int:
        # rearrange the formula: nums[i] - i != nums[j] - j
        hmap = dict()
        N = len(nums)
        good = 0
        for i, num in enumerate(nums):
            curr = num - i
            if curr in hmap:
                good += hmap[curr]
            hmap[curr] = hmap.get(curr, 0) + 1
            
        return N*(N-1)//2 - good