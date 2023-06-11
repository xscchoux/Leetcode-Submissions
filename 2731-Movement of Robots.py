class Solution:
    def sumDistance(self, nums: List[int], s: str, d: int) -> int:
        kMod = 10**9+7
        for i in range(len(nums)):
            if s[i] == "R":
                nums[i] += d
            else:
                nums[i] -= d
        
        nums.sort()
        
        prev = 0 # sum of distances from all previous points to current point
        res = 0
        
        for i in range(1, len(nums)):
            prev = (prev + i*(nums[i] - nums[i-1]))%kMod
            res = (res + prev)%kMod
            
        return res