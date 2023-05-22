from heapq import heappush, heappop
class Solution:
    def minMeetingRooms(self, intervals: List[List[int]]) -> int:
        
# sweep line
        arr = []
        curr = res = 0
        
        for interval in intervals:
            arr.append((interval[0], 1))
            arr.append((interval[1], -1))
        
        arr.sort(key = lambda x:(x[0], x[1]))
        
        for i in range(len(arr)):
            if arr[i][1] == 1:
                curr += 1
            else:
                curr -= 1
            res = max(res, curr)
            
        return res
    
# heap, beautiful solution
        intervals.sort(key = lambda x:x[0])
        pq = []
        
        for interval in intervals:
            if pq and interval[0] >= pq[0]:
                heappop(pq)
                
            heappush(pq, interval[1])
        
        return len(pq)