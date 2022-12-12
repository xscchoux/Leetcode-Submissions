from sortedcontainers import SortedList
class Allocator(object):

    def __init__(self, n):
        """
        :type n: int
        """
        self.n = n
        self.seg = SortedList()

    def allocate(self, size, mID):
        """
        :type size: int
        :type mID: int
        :rtype: int
        """
        left = 0
        for start, length, _ in self.seg:
            if start - left  >= size:
                self.seg.add((left, size, mID))
                return left
            else:
                left = start+length
                    
        if left + size-1 <= self.n-1:
            self.seg.add((left, size, mID))
            return left
        return -1
                    

    def free(self, mID):
        """
        :type mID: int
        :rtype: int
        """
        count = 0
        ind = 0
        while ind < len(self.seg):
            if self.seg[ind][2] == mID:
                count += self.seg[ind][1]
                self.seg.discard(self.seg[ind])
            else:
                ind+=1

        return count

# Your Allocator object will be instantiated and called as such:
# obj = Allocator(n)
# param_1 = obj.allocate(size,mID)
# param_2 = obj.free(mID)