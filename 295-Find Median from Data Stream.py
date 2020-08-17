import heapq
class MedianFinder(object):

    # use two heaps, upper heap is a min heap, and lower heap is a max heap   O(lgn)

    def __init__(self):
        """
        initialize your data structure here.
        """
        self.upperheap = [] # minheap
        self.lowerheap = [] # maxheap

    def addNum(self, num):
        """
        :type num: int
        :rtype: None
        """
        if not self.upperheap or num > self.upperheap[0]:
            heapq.heappush(self.upperheap, num)
        else:
            heapq.heappush(self.lowerheap, (-1)*num)
            
        #balance
        if len(self.upperheap) - len(self.lowerheap) > 1:
            heapq.heappush(self.lowerheap, (-1)*heapq.heappop(self.upperheap))
        elif len(self.lowerheap) - len(self.upperheap) >= 1:
            heapq.heappush(self.upperheap, (-1)*heapq.heappop(self.lowerheap))

    def findMedian(self):
        """
        :rtype: float
        """
        if len(self.lowerheap) == len(self.upperheap):
            return ((-1)*self.lowerheap[0] + self.upperheap[0])/float(2)
        else:
            return self.upperheap[0]