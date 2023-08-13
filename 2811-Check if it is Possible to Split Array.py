class Solution:
    def canSplitArray(self, nums: List[int], m: int) -> bool:
# DP, first try
        if len(nums) == 1:
            return True
        preSum = [0]
        for num in nums:
            preSum.append(preSum[-1]+num)
        
        @cache
        def dfs(start, end):
            if start == end:
                return True
            
            if end - start >= 1 and preSum[end+1] - preSum[start] < m:
                return False
            
            for i in range(start, end):
                if dfs(start, i) and dfs(i+1, end):
                    return True
            
            return False
        
        for i in range(len(nums)-1):
            if dfs(0, i) and dfs(i+1, len(nums)-1):
                return True
        
        return False
    
# best solution, mind-blowing
        if len(nums) <= 2:
            return True
        for i in range(len(nums)-1):
            if nums[i+1] + nums[i] >= m:
                return True
        return False