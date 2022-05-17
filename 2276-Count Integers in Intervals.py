from sortedcontainers import SortedList
from bisect import bisect_right
# https://www.youtube.com/watch?v=XS4wCS9sLsk
# O(NlogN)
class CountIntervals(object):

    def __init__(self):
        self.sl = SortedList()
        self.num = 0
        
    def add(self, left, right):
        """
        :type left: int
        :type right: int
        :rtype: None
        """
        ind = self.sl.bisect_right((left, right)) - 1
        remove = []
        
        leftMost, rightMost = left, right
        
        if ind != -1:
            L, R = self.sl[ind]
            if L <= left <= right <= R:
                return
            if L <= left <= R < right:
                remove.append((L, R))
                leftMost = L
                self.num -= (R - left + 1)
        ind += 1
        
        while ind < len(self.sl):
            L, R = self.sl[ind]
            if left <= L <= R <= right:
                remove.append((L, R))
                self.num -= (R-L+1)
                ind += 1
            else:
                break

        if ind < len(self.sl):
            L, R = self.sl[ind]
            if left <= L <= right <= R:
                remove.append((L, R))
                self.num -= (right-L+1)
                rightMost = R
        
        for interval in remove:
            self.sl.remove(interval)
        
        self.num += (right-left+1)
        self.sl.add((leftMost, rightMost))

    def count(self):
        """
        :rtype: int
        """
        return self.num
        

# Your CountIntervals object will be instantiated and called as such:
# obj = CountIntervals()
# obj.add(left,right)
# param_2 = obj.count()