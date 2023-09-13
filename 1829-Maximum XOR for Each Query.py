class Solution:
    def getMaximumXor(self, nums: List[int], maximumBit: int) -> List[int]:
        res = []
        N = len(nums)
        preXOR = 0
        mx = pow(2, maximumBit)-1
        
        for i in range(N):
            preXOR = preXOR^nums[i]
            res.append(mx^preXOR)
            
        return res[::-1]