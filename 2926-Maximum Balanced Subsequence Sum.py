from sortedcontainers import SortedList
class Solution:
    def maxBalancedSubsequenceSum(self, nums: List[int]) -> int:
        # nums[j] - j >= nums[j-1] - (j-1)
        sl = SortedList()  # (nums[i]-i, max_sum_so_far[i])
        N = len(nums)
        res = float('-inf')
        
        for i in range(N):
            if nums[i] <= 0:
                continue
            idx = sl.bisect_right((nums[i]-i, float('inf')))

            if idx-1 < 0:
                prevSum = 0
            else:
                prevSum = sl[idx-1][1]

            currSum = nums[i] + prevSum
            
            sl.add((nums[i]-i, currSum))

            while idx+1 < len(sl) and currSum > sl[idx+1][1]:
                del sl[idx+1]
            
            res = max(res, currSum)

        return max(nums) if res == float('-inf') else res