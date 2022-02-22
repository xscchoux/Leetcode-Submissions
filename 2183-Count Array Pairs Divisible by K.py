class Solution:
    def countPairs(self, nums: List[int], k: int) -> int:
        
# https://www.youtube.com/watch?v=QDJya-uywDE
# O(NlogN + N*sqrt(N)), there are about sqrt(N) factors in factorSet

        factorSet = set()
        
        for i in range(1, int(k**0.5)+1):
            if k%i != 0:
                continue
            factorSet.add(i)
            factorSet.add(k//i)
        
        factorMap = collections.defaultdict(list)
        
        for i in range(len(nums)):
            for factor in factorSet:
                if nums[i]%factor == 0:
                    factorMap[factor].append(i)
        
        res = 0
        
        for i in range(len(nums)):
            a = math.gcd(nums[i], k)
            b = k//a
            idx = bisect.bisect_right(factorMap[b], i)
            res += len(factorMap[b]) - idx
        
        return res