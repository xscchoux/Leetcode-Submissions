class Solution:
    def minOperations(self, nums: List[int], queries: List[int]) -> List[int]:
        N = len(nums)
        M = len(queries)
        nums.sort()
        prefix_sum = [0]*N
        prefix_sum[0] = nums[0]
        
        for i in range(1, N):
            prefix_sum[i] = prefix_sum[i-1] + nums[i]

        ans = []
        for q in queries:
            pos = bisect_left(nums, q)

            if pos == N:
                ans.append(q*N-prefix_sum[-1]) # don't need this actually
            else:
                if pos >= 1:
                    ans.append(q*pos-prefix_sum[pos-1] + (prefix_sum[-1]-prefix_sum[pos-1])-q*(N-pos))
                else:
                    ans.append(prefix_sum[-1]-q*N)
        return ans