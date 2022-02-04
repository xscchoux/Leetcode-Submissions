from sortedcontainers import SortedList
class SORTracker(object):

    def __init__(self):
        self.ind = 0
        self.slist = SortedList()

    def add(self, name, score):
        """
        :type name: str
        :type score: int
        :rtype: None
        """
        self.slist.add((-score, name))

    def get(self):
        """
        :rtype: str
        """
        res = self.slist[self.ind][1]
        self.ind += 1
        return res

# Your SORTracker object will be instantiated and called as such:
# obj = SORTracker()
# obj.add(name,score)
# param_2 = obj.get()