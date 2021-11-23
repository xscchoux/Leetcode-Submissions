class FirstUnique(object):

    def __init__(self, nums):
        """
        :type nums: List[int]
        """
        self.hmap = dict()  # number to index
        self.queue = collections.deque([])
        
        for num in nums:
            self.add(num)

    def showFirstUnique(self):
        """
        :rtype: int
        """
        while self.queue and self.hmap[self.queue[0]] == -1:
            self.queue.popleft()
        if self.queue:
            return self.queue[0]
        else:
            return -1
        
    def add(self, value):
        """
        :type value: int
        :rtype: None
        """
        if value in self.hmap:
            self.hmap[value] = -1
        else:
            self.queue.append(value)
            self.hmap[value] = 1