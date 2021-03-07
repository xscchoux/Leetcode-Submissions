import heapq
class Solution(object):
    def maxEvents(self, events):
        """
        :type events: List[List[int]]
        :rtype: int
        """
# Time complexity: O(100000 + nlogn)
        events.sort(key = lambda x: (x[0], x[1]))
        N = len(events)
        res = 0
        pq = []
        idx = 0
        for day in range(1, 100001):
# remove old events
            while pq and pq[0] < day:
                heapq.heappop(pq)
# add endtime of event events
            while idx < N and events[idx][0] <= day:
                heapq.heappush(pq, events[idx][1])
                idx+=1
            if pq and pq[0] >= day:
                heapq.heappop(pq)
                res += 1
        
        return res