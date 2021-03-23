class Solution(object):
    def shipWithinDays(self, weights, D):
        """
        :type weights: List[int]
        :type D: int
        :rtype: int
        """
        
        def countDay(load):
            DayCount = 1
            weightSum = 0
            for i in range(len(weights)):
                if weightSum + weights[i] > load:
                    weightSum = weights[i]
                    DayCount += 1
                else:
                    weightSum += weights[i]
            return DayCount        
            
        left, right = max(weights), sum(weights)
        
        while left + 1 < right:
            mid = left + (right-left)//2
            if countDay(mid) <= D:
                right = mid
            else:
                left = mid
        
        if countDay(left) <= D:
            return left
        else:
            return right