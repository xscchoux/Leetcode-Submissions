class TimeMap(object):

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.hmap = {}

    def set(self, key, value, timestamp):
        """
        :type key: str
        :type value: str
        :type timestamp: int
        :rtype: None
        """
        if key in self.hmap:
            self.hmap[key].append((timestamp, value))  # note that timestamps are strictly increasing
        else:
            self.hmap[key] = [(timestamp, value)]

    def get(self, key, timestamp):
        """
        :type key: str
        :type timestamp: int
        :rtype: str
        """
        # binary search
        if key not in self.hmap or timestamp < self.hmap[key][0][0]:
            return ""
        else:
            arr = self.hmap[key]
            left, right = 0, len(arr)-1
            while left + 1 < right:
                mid = left + (right-left)//2
                if arr[mid][0] > timestamp:
                    right = mid
                else:
                    left = mid

            if arr[right][0] <= timestamp:
                return arr[right][1]
            else:
                return arr[left][1]