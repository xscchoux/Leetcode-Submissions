class Solution(object):
    def findMinDifference(self, timePoints):
        """
        :type timePoints: List[str]
        :rtype: int
        """
        time = [60*int(t[:2]) + int(t[-2:]) for t in timePoints]
        time.sort()
        
        res = 1440
        for i in range(1, len(time)):
            res = min(res, time[i] - time[i-1])
        
        res = min(res, 1440-(time[-1]-time[0]) )
        
        return res