from sortedcontainers import SortedList
class MRUQueue:

    def __init__(self, n: int):
        self.sl = SortedList()
        for i in range(1, n+1):
            self.sl.add((i, i))

    def fetch(self, k: int) -> int:
        _, x = self.sl.pop(k-1)
        ind = self.sl[-1][0] if self.sl else 0
        self.sl.add((ind+1, x))
        return x

# Your MRUQueue object will be instantiated and called as such:
# obj = MRUQueue(n)
# param_1 = obj.fetch(k)