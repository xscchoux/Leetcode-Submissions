binaryPal = []

for num in range(1, 5001):
    binS = bin(num)[2:]
    if binS == binS[::-1]:
        binaryPal.append(num)

class Solution:
    def minOperations(self, nums: List[int]) -> List[int]:
        res = []

        for num in nums:
            idx = bisect_left(binaryPal, num)
            val = 5000
            for i in range(idx-1, idx+1):
                try:
                    val = min(val, abs(num-binaryPal[i]))
                except:
                    continue
            res.append(val)
        
        return res