class Solution:
    def sumOfPower(self, nums: List[int]) -> int:
        nums.sort()
        res = 0
        kMod = 10**9 + 7
        tot = 0  # sum of minimum values of subsets that uses nums[:i]

        for i in range(len(nums)):
            res = (res + pow(nums[i], 3, kMod))%kMod
            
            res = (res + (pow(nums[i], 2, kMod)*tot)%kMod )%kMod
            tot = (tot*2 + nums[i])%kMod
        
        return res