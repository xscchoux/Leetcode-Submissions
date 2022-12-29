#https://leetcode.com/problems/single-threaded-cpu/discuss/1164082/Clean-Python-3-heap
from heapq import heappush, heappop
class Solution:
    def getOrder(self, tasks: List[List[int]]) -> List[int]:
        enqueue = []
        res = []
        tasks = [(s, d, i) for i, (s, d) in enumerate(tasks)]
        tasks.sort()
        endTime = 0
        
        for start, duration, ind in tasks:
            while enqueue and endTime < start:
                d, index, s = heappop(enqueue)
                endTime = max(s, endTime) + d
                res.append(index)
            heappush(enqueue, (duration, ind, start))
            
        while enqueue:
            _, index, _ = heappop(enqueue)
            res.append(index)
            
        return res