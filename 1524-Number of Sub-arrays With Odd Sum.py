class Solution:
    def numOfSubarrays(self, arr: List[int]) -> int:
        running = 0
        odd, even = 0, 1
        kMod = 10**9+7
        res = 0
        
        for num in arr:
            running += num
            if running%2 == 0:
                res = (res + odd)%kMod
            else:
                res = (res + even)%kMod
            
            if running%2 == 0:
                even += 1
            else:
                odd += 1
        
        return res