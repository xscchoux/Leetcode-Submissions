from heapq import heappush, heappop
class Solution:
    def minGroups(self, intervals: List[List[int]]) -> int:
        
        res = 0
        intervals.sort(key = lambda x:x[0])
        pq = []
        
        for start, end in intervals:
            if not pq or start <= pq[0]:
                res += 1
            else:
                heappop(pq)
            heappush(pq, end)
                
        return res
