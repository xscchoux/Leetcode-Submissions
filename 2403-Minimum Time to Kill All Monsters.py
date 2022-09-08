class Solution:
    def minimumTime(self, power: List[int]) -> int:
# O(N*2^N)
        N = len(power)
        
        @cache
        def dfs(ind, bitmask):
            if ind == N:
                return 0
            res = float('inf')
            gain = ind+1
            for i in range(len(power)):
                if (bitmask >> i) & 1 == 0:
                    if gain >= power[i]:
                        res = min(res, 1+dfs(ind+1, bitmask^(1<<i)))
                    else:
                        q, r = divmod(power[i], gain)
                        res = min(res, q + (r!=0) + dfs(ind+1, bitmask^(1<<i)))
            return res
        
        ans = dfs(0, 0)
        return ans