from collections import deque
class ZigzagIterator(object):

    def __init__(self, v1, v2):
        """
        Initialize your data structure here.
        :type v1: List[int]
        :type v2: List[int]
        """
        self.arr = [v for v in (v1,v2) if v]
        self.queue = deque([(vIndex, 0) for vIndex in range(len(self.arr))])

    def next(self):
        """
        :rtype: int
        """
        vIndex, index = self.queue.popleft()
        if index < len(self.arr[vIndex]) - 1:
            self.queue.append((vIndex, index+1))
        return self.arr[vIndex][index]

    def hasNext(self):
        """
        :rtype: bool
        """
        return bool(self.queue)

# Your ZigzagIterator object will be instantiated and called as such:
# i, v = ZigzagIterator(v1, v2), []
# while i.hasNext(): v.append(i.next())