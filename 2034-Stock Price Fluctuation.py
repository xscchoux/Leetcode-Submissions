from heapq import heappush, heappop
class StockPrice(object):
# https://leetcode.com/problems/stock-price-fluctuation/discuss/1513324/Python3-hash-map-and-2-heaps
    def __init__(self):
        self.latest = 0
        self.hmap = collections.defaultdict(int)
        self.maxHeap = []
        self.minHeap = []

    def update(self, timestamp, price):
        """
        :type timestamp: int
        :type price: int
        :rtype: None
        """
        if timestamp > self.latest:
            self.latest = timestamp
        self.hmap[timestamp] = price    
        heappush(self.maxHeap, (-price, timestamp))
        heappush(self.minHeap, (price, timestamp))
        
    def current(self):
        """
        :rtype: int
        """
        return self.hmap[self.latest]

    def maximum(self):
        """
        :rtype: int
        """
        while self.maxHeap[0][0] != -self.hmap[self.maxHeap[0][1]]:
            heappop(self.maxHeap)
        return -self.maxHeap[0][0]

    def minimum(self):
        """
        :rtype: int
        """
        while self.minHeap[0][0] != self.hmap[self.minHeap[0][1]]:
            heappop(self.minHeap)
        return self.minHeap[0][0]

# Your StockPrice object will be instantiated and called as such:
# obj = StockPrice()
# obj.update(timestamp,price)
# param_2 = obj.current()
# param_3 = obj.maximum()
# param_4 = obj.minimum()