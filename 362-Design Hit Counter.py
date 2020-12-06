class HitCounter(object):

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.count = []

    def hit(self, timestamp):
        """
        Record a hit.
        @param timestamp - The current timestamp (in seconds granularity).
        :type timestamp: int
        :rtype: None
        """
        self.count.append(timestamp)

    def getHits(self, timestamp):
        """
        Return the number of hits in the past 5 minutes.
        @param timestamp - The current timestamp (in seconds granularity).
        :type timestamp: int
        :rtype: int
        """
        if timestamp <= 300:
            return len(self.count)
        else:
            time = timestamp - 300
            left = 0
            right = len(self.count) - 1
            while left + 1 < right:
                mid = left + (right - left)//2
                if self.count[mid] > time:
                    right = mid
                else:
                    left = mid

            if self.count[left] > time:
                res = len(self.count) - left
                return res
            elif self.count[right] > time:
                res = len(self.count) - right
                return res
            return 0
                