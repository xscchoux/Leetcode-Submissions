class Solution:
    def countBeautifulPairs(self, nums: List[int]) -> int:
        cnt = [0]*10
        res = 0
        
        for x in nums:
            for num in range(10):
                if gcd(num, x%10) == 1:
                    res += cnt[num]
            while x >= 10:
                x = x//10
            cnt[x] += 1
        
        return res