class Vector2D(object):

    def __init__(self, v):
        """
        :type v: List[List[int]]
        """
        self.res = v
            
    def next(self):
        """
        :rtype: int
        """
        if self.hasNext():
            return self.res.pop(0)

    def hasNext(self):
        """
        :rtype: bool
        """
        def recursive():
            if not self.res:
                return False
            if isinstance(self.res[0], list):
                arr = self.res.pop(0)
                self.res = arr + self.res
                return recursive()
            else:
                return True
        return recursive()

# Your Vector2D object will be instantiated and called as such:
# obj = Vector2D(v)
# param_1 = obj.next()
# param_2 = obj.hasNext()