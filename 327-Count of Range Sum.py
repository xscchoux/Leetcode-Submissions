from sortedcontainers import SortedList
class Solution:
    def countRangeSum(self, nums: List[int], lower: int, upper: int) -> int:
        sl = SortedList()
        sl.add(0)
        res = tot = 0
        
        # lower <= preSum[i] - preSum[j] <= upper
        # preSum[i] - upper <= preSum[j(left)]
        # preSum[i] - lower < preSum[j(right)]
        
        for num in nums:
            tot += num
            left = sl.bisect_left(tot-upper)
            right = sl.bisect_left(tot-(lower-1))
            res += (right-left)
            sl.add(tot)
            
        return res