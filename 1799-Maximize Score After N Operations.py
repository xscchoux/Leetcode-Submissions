class Solution:
    def maxScore(self, nums: List[int]) -> int:
        N = len(nums)
        
        mm = []
        for i in range(N):
            for j in range(i+1, N):
                mm.append([gcd(nums[i], nums[j]), (1<<i)|(1<<j)] )
        
        @cache
        def dfs(bitmap, ind):
            if ind == N:
                return 0
            
            res = 0
            for val, m in mm:
                if not bitmap&m:
                    res = max(res, (ind+1)*val + dfs(bitmap^m,ind+1))
            return res
        
        return dfs(0, 0)