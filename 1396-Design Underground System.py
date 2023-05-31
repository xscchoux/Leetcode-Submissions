class UndergroundSystem(object):

    def __init__(self):
        self.user = {}
        self.station = collections.defaultdict(list)

    def checkIn(self, id, stationName, t):
        """
        :type id: int
        :type stationName: str
        :type t: int
        :rtype: None
        """
        self.user[id] = (stationName, t)

    def checkOut(self, id, stationName, t):
        """
        :type id: int
        :type stationName: str
        :type t: int
        :rtype: None
        """
        stationStart, tStart = self.user[id]
        self.station[(stationStart, stationName)].append(t-tStart)

    def getAverageTime(self, startStation, endStation):
        """
        :type startStation: str
        :type endStation: str
        :rtype: float
        """
        tmp = self.station[(startStation, endStation)]
        return sum(tmp)/float(len(tmp))


# Your UndergroundSystem object will be instantiated and called as such:
# obj = UndergroundSystem()
# obj.checkIn(id,stationName,t)
# obj.checkOut(id,stationName,t)
# param_3 = obj.getAverageTime(startStation,endStation)


# Another solution

class UndergroundSystem:

    def __init__(self):
        self.id = defaultdict(int) # id:startTime
        self.pair = defaultdict(lambda : [0, 0])

    def checkIn(self, id: int, stationName: str, t: int) -> None:
        self.id[id] = (t, stationName)

    def checkOut(self, id: int, stationName: str, t: int) -> None:
        startTime, startStation = self.id[id]
        self.pair[(startStation, stationName)][0] += t - startTime
        self.pair[(startStation, stationName)][1] += 1

    def getAverageTime(self, startStation: str, endStation: str) -> float:
        totTime, totCount = self.pair[(startStation, endStation)]
        return totTime/totCount


# Your UndergroundSystem object will be instantiated and called as such:
# obj = UndergroundSystem()
# obj.checkIn(id,stationName,t)
# obj.checkOut(id,stationName,t)
# param_3 = obj.getAverageTime(startStation,endStation)