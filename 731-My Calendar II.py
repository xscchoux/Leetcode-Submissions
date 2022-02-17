from sortedcontainers import SortedList
class MyCalendarTwo(object):

    def __init__(self):
        self.arr = SortedList()

    def book(self, start, end):
        """
        :type start: int
        :type end: int
        :rtype: bool
        """
        self.arr.add((start, 1))
        self.arr.add((end, -1))
        intervals = 0
        for x, num in self.arr:
            intervals += num
            if intervals == 3:
                self.arr.remove((start, 1))
                self.arr.remove((end, -1))
                return False
        return True


# Your MyCalendarTwo object will be instantiated and called as such:
# obj = MyCalendarTwo()
# param_1 = obj.book(start,end)