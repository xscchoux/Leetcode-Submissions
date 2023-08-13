from sortedcontainers import SortedList
class Solution:
    def minAbsoluteDifference(self, nums: List[int], x: int) -> int:
        sl = SortedList()
        res = float('inf')
        
        for i in range(len(nums)):
            if i >= x:
                sl.add(nums[i-x])
                idx = sl.bisect_left(nums[i])
                for j in range(idx-1, idx+1):
                    try:
                        res = min(res, abs(sl[j] - nums[i]))
                    except:
                        continue
        return res
    
    
from heapq import *
class Solution:
    def minAbsoluteDifference(self, nums: List[int], x: int) -> int:
        if x == 0:
            return 0
        res = float('inf')
        arr = sorted([(num, i) for i, num in enumerate(nums)])
        pq1, pq2 = [], [] # keep previous indexes and values
        
        for num, i in arr:
            while pq1 and pq1[0][0] <= i-x:    # smaller values with index <= i + x
                res = min(res, num - heappop(pq1)[1])
            while pq2 and -pq2[0][0] >= i+x:   # smaller values with index >= i + x
                res = min(res, num - heappop(pq2)[1])
            
            heappush(pq1, (i, num))
            heappush(pq2, (-i, num))
            
        return res