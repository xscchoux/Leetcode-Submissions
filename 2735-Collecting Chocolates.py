class Solution:
    def minCost(self, nums: List[int], x: int) -> int:
        N = len(nums)      
        minCost = float('inf')
        current = nums[:]
        
        for t in range(N):
            for i in range(N):
                if current[i] > nums[((i-t))%N]:
                    current[i] = min(current[i], nums[((i-t))%N])
            minCost = min(minCost, sum(current) + x*t)

        return minCost