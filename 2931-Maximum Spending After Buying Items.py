from heapq import *
class Solution:
    def maxSpending(self, values: List[List[int]]) -> int: 
    # basic O(mnlog(mn))
        arr = []
        for i in range(len(values)):
            for x in values[i]:
                arr.append(x)
        arr.sort()
        
        res = 0
        for i, val in enumerate(arr, 1):
            res += val*i
        
        return res
    
    # Use heap, O(mnlogm)
        m, n = len(values), len(values[0])
        res = 0
        pq = []
        for i, arr in enumerate(values):
            pq.append((arr.pop(), i))
        
        heapify(pq)
        
        for i in range(1, m*n+1):
            val, idx = heappop(pq)
            res += val*i
            if values[idx]:
                heappush(pq, (values[idx].pop(), idx))
        
        return res