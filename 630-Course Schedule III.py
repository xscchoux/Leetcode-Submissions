from heapq import heappush, heappop
class Solution(object):
    def scheduleCourse(self, courses):
        """
        :type courses: List[List[int]]
        :rtype: int
        """
# sort + priority queue
        pq = []
        courses.sort(key = lambda x: x[1])
        elapsed = 0
        
        for duration, deadline in courses:
            elapsed += duration
            heappush(pq, -duration)
            if elapsed > deadline:
                elapsed -= -pq[0]
                heappop(pq)
        
        return len(pq)