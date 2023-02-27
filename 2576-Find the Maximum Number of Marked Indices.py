class Solution:
    def maxNumOfMarkedIndices(self, nums: List[int]) -> int: 
        N = len(nums)
        nums.sort()
        i = res = 0
        
        for j in range(N - N//2, N):
            if nums[i]*2 <= nums[j]:
                i += 1
                res += 2
                
        return res