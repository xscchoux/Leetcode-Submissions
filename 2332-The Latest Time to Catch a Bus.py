class Solution(object):
    def latestTimeCatchTheBus(self, buses, passengers, capacity):
        """
        :type buses: List[int]
        :type passengers: List[int]
        :type capacity: int
        :rtype: int
        """
        buses.sort()
        passengers.sort()
        
        j = 0
        res = 1
        for i in range(len(buses)):
            currEnd = buses[i]
            currCap = capacity
            while j < len(passengers) and passengers[j] <= currEnd and currCap > 0:
                if j == 0:
                    res = passengers[j] - 1
                else:
                    if passengers[j-1] != passengers[j] - 1:
                        res = passengers[j] - 1
                currCap -= 1
                j+=1
                
            if currCap > 0:
                if passengers[j-1] != currEnd:
                    res = currEnd
                    
        return res