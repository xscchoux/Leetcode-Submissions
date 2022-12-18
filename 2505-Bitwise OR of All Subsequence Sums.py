class Solution:
    def subsequenceSumOr(self, nums: List[int]) -> int:

        # log2(10^14) = 46.5....
        
        bitcount = 0
        res = 0
        
        for i in range(47):
            bitcount = bitcount//2
            for num in nums:
                if (num>>i) & 1:
                    bitcount += 1
            if bitcount > 0:
                res |= (1<<i)
        
        return res