from heapq import heappush, heappop
class Solution(object):
    def eatenApples(self, apples, days):
        """
        :type apples: List[int]
        :type days: List[int]
        :rtype: int
        """
        res = curr = 0
        pq = []
        N = len(apples)
        
        while curr < N or pq:
            while pq and (pq[0][0] <= curr or pq[0][1] == 0):
                heappop(pq)
                
            if curr < N and apples[curr] > 0:
                apple, day = apples[curr], days[curr]
                heappush(pq, [curr + day, apple])

            # # eat
            if pq:
                pq[0][1] -= 1
                res += 1
            curr += 1
            
        return res