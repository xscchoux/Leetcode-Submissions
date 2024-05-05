class Solution:
    def minimumValueSum(self, nums: List[int], andValues: List[int]) -> int:
        # O(N*M*17), note that there are at most 17 bitwise AND values between each (i, j)
        N, M = len(nums), len(andValues)
        full = (1<<17)-1  # need bracket here, 10^5 < 2^17

        @cache
        def dfs(ind, j, curr):
            if ind == N and j == M:
                return 0
            elif ind == N or j == M:
                return inf
            
            res = inf
            if curr&nums[ind] == andValues[j]:
                res = nums[ind] + dfs(ind+1, j+1, full)
            
            res = min(res, dfs(ind+1, j, curr&nums[ind]))
        
            return res

        ans = dfs(0, 0, full)

        return ans if ans < inf else -1