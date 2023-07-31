class Solution:
    def maxScore(self, nums: List[int], x: int) -> int:
        
# DP1
        N = len(nums)
    
        @cache
        def dfs(idx, parity): # parity: the parity of last number
            if idx == N:
                return 0
            curr_parity = nums[idx]%2
            return max( dfs(idx+1, parity), nums[idx] - x*(parity^curr_parity) + dfs(idx+1, curr_parity) )

        return nums[0] + dfs(1, nums[0]%2)
        
# DP2
        oddMax = evenMax = 0 # max value if last number is odd/even
        
        if nums[0]%2 == 0:
            evenMax = nums[0]
            oddMax = nums[0] - x
        else:
            evenMax = nums[0] - x
            oddMax = nums[0]
        
        for num in nums[1:]:
            if num%2 == 1:
                oddMax = max(num + oddMax, num + evenMax -x)
            else:
                evenMax = max(num + evenMax, num + oddMax -x)
        
        return max(evenMax, oddMax)