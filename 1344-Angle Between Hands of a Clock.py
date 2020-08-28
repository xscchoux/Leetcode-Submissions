class Solution(object):
    def angleClock(self, hour, minutes):
        """
        :type hour: int
        :type minutes: int
        :rtype: float
        """
        hourAngle = (hour%12)*30 + 30*(minutes / float(60))
        minuteAngle = (minutes/float(5))*30
        
        res = abs(hourAngle-minuteAngle)
        
        if res > 180:
            res = 360 - res
        
        return res