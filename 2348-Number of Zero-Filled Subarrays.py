class Solution:
    def zeroFilledSubarray(self, nums: List[int]) -> int:
        res = subarray = 0
        
        for c in nums:
            if c == 0:
                subarray += 1
                res += subarray
            else:
                subarray = 0
                
        return res