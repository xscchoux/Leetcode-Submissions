class Solution:
    def minimumReplacement(self, nums: List[int]) -> int:
        prevMin = nums[-1]
        res = 0
        
        for i in range(len(nums)-2, -1, -1):
            if nums[i] > prevMin:
                cut = nums[i]//prevMin
                if nums[i]%prevMin == 0:
                    res += cut-1
                else:
                    res += cut
                    prevMin = nums[i]//(cut+1)
            else:
                prevMin = nums[i]
        return res