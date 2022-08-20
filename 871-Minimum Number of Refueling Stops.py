from heapq import heappush, heappop
class Solution(object):
    def minRefuelStops(self, target, startFuel, stations):
        """
        :type target: int
        :type startFuel: int
        :type stations: List[List[int]]
        :rtype: int
        """
        pq = []
        stations.append([target, 0])
        currFuel = startFuel
        res = 0
        prev = 0
        
        for pos, fuel in stations:
            diff = pos - prev
            while pq and currFuel < diff:
                currFuel -= heappop(pq)
                res += 1
            if currFuel < diff:
                return -1
            currFuel -= diff
            heappush(pq, -1*fuel)
            prev = pos
                
        return res