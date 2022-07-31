class Vector2D(object):

    def __init__(self, vec):
        """
        :type vec: List[List[int]]
        """
        self.arr = vec
        self.inner = 0
        self.outer = 0
    
    def forward(self):
        while self.outer < len(self.arr) and self.inner == len(self.arr[self.outer]):
            self.outer += 1
            self.inner = 0
    
    def next(self):
        """
        :rtype: int
        """
        self.forward()     
        res = self.arr[self.outer][self.inner]
        self.inner += 1
        return res
    
    def hasNext(self):
        """
        :rtype: bool
        """
        self.forward()
        
        return self.outer < len(self.arr)

# Your Vector2D object will be instantiated and called as such:
# obj = Vector2D(vec)
# param_1 = obj.next()
# param_2 = obj.hasNext()