class Solution:
    def minOperations(self, nums: List[int]) -> int:
        if gcd(*nums) != 1:
            return -1
        
        count = sum([num == 1 for num in nums])
        if count > 0:
            return len(nums) - count
        
        res = float('inf')
        for i in range(len(nums)):
            currGCD = nums[i]
            for j in range(i+1, len(nums)):
                currGCD = gcd(currGCD, nums[j])
                if currGCD == 1:
                    res = min(res, j-i + len(nums)-1)
        
        return res