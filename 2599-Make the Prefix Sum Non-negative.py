from heapq import heappush, heappop
class Solution:
    def makePrefSumNonNegative(self, nums: List[int]) -> int:
        # If you reach a point where the prefix sum is less than zero, it's always best to push the minimum element so far to the end.
        pq = []
        tot = res = 0
        
        for num in nums:
            tot += num
            heappush(pq, num)
            if tot < 0:
                tot -= heappop(pq)
                res += 1
        
        return res