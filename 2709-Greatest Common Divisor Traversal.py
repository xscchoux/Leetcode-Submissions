class Solution:
    def canTraverseAllPairs(self, nums: List[int]) -> bool:
        if len(nums) == 1:
            return True
        
        if 1 in nums:
            return False
        
        def find(x):
            if parent[x] != x:
                parent[x] = find(parent[x])
            return parent[x]
        
        def union(a, b):
            pa, pb = find(a), find(b)
            if pa != pb:
                parent[pb] = pa
        
        nums = list(set(nums))
        N = len(nums)
        parent = {i:i for i in range(N)}
        factorMap= {}

        for i, num in enumerate(nums):
            for j in range(2, isqrt(num) + 1):
                if num % j == 0:
                    if j not in factorMap:
                        factorMap[j] = i
                    else:
                        union(i, factorMap[j])
                    while num%j == 0:
                        num = num//j
            if num == 1:
                continue
            if num not in factorMap:
                factorMap[num] = i
            else:
                union(i, factorMap[num])
                
        connected = set()
        for i in range(N):
            connected.add(find(i))

        return len(connected) == 1