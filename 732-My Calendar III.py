from sortedcontainers import SortedList
class MyCalendarThree:

    def __init__(self):
        self.arr = SortedList()

    def book(self, start: int, end: int) -> int:
        self.arr.add((start, 1))
        self.arr.add((end, -1))
        
        res = cur = 0
        
        for val, label in self.arr:
            cur += label
            res = max(res, cur)
        
        return res

# Your MyCalendarThree object will be instantiated and called as such:
# obj = MyCalendarThree()
# param_1 = obj.book(start,end)