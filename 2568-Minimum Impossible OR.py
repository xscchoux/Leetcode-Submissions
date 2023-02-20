class Solution:
    def minImpossibleOR(self, nums: List[int]) -> int:
        powerOfTwo = set()
        
        for num in nums:
            if num&(num-1) == 0:
                powerOfTwo.add(num)
        
        curr = 1
        while curr in powerOfTwo:
            curr = curr << 1
        return curr