class OrderedStream(object):

    def __init__(self, n):
        """
        :type n: int
        """
        self.hmap = dict()
        for i in range(1, n+1):
            self.hmap[i] = []
        self.ptr = 1
        self.n = n

    def insert(self, id, value):
        """
        :type id: int
        :type value: str
        :rtype: List[str]
        """
        self.hmap[id] = value
        if id != self.ptr:
            return []
        res = []
        
        while self.ptr <=self.n and self.hmap[self.ptr]:
            res.append(self.hmap[self.ptr])
            self.ptr += 1
        
        return res