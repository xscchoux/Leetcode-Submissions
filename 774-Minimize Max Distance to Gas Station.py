class Solution(object):
    def minmaxGasDist(self, stations, k):
        """
        :type stations: List[int]
        :type k: int
        :rtype: float
        """
        left, right = 0, max(stations)
        
        def canAdd(dist):
            res = 0
            for i in range(1, len(stations)):
                res += (stations[i]-stations[i-1])//dist
            
            return res<=k
        
        
        while left + 10**(-6) <= right:
            mid = left + (right-left)/float(2)
            if canAdd(mid):
                right = mid
            else:
                left = mid
                
        return right