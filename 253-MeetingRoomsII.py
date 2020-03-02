import heapq
class Solution(object):
    def minMeetingRooms(self, intervals):
        """
        :type intervals: List[List[int]]
        :rtype: int
        """
        if not intervals:
            return 0
        intervals.sort()
        minheap = [intervals[0][1]]
        
        for i in range(1, len(intervals)):
            if intervals[i][0] >= minheap[0]:
                heapq.heappop(minheap)
            heapq.heappush(minheap,intervals[i][1])
        
        return len(minheap)