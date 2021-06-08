import heapq
class Solution(object):
    def maxPerformance(self, n, speed, efficiency, k):
        """
        :type n: int
        :type speed: List[int]
        :type efficiency: List[int]
        :type k: int
        :rtype: int
        """
        kMod = 10**9+7
        pq = []
        totSpeed = 0
        res = 0
        
        for e, s in sorted(zip(efficiency, speed), reverse = True):
            heappush(pq, s)
            totSpeed += s
            if len(pq) > k:
                totSpeed -= heappop(pq)
            res = max(res, totSpeed*e)
        
        return res%kMod