class Solution:
    def minOperations(self, nums: List[int]) -> int:
        res = 0
        count = Counter(nums)
        
        for v in count.values():
            if v == 1:
                return -1
            while v%3 != 0:
                v -= 2
                res+= 1
            res += v//3
            
        return res