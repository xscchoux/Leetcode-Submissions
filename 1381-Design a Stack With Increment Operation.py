class CustomStack(object):

    def __init__(self, maxSize):
        """
        :type maxSize: int
        """
        self.maxSize = maxSize
        self.stack = []
        self.inc = []

    def push(self, x):
        """
        :type x: int
        :rtype: None
        """
        if len(self.stack) < self.maxSize:
            self.stack.append(x)
            self.inc.append(0)

    def pop(self):
        """
        :rtype: int
        """
        if self.stack:
            offset = self.inc[-1]
            if len(self.inc) > 1:
                self.inc[-2] += self.inc[-1]
            self.inc.pop()
            return self.stack.pop() + offset 
        else:
            return -1

    def increment(self, k, val):
        """
        :type k: int
        :type val: int
        :rtype: None
        """
        if self.inc:
            self.inc[min(k-1, len(self.inc)-1)] += val


# Your CustomStack object will be instantiated and called as such:
# obj = CustomStack(maxSize)
# obj.push(x)
# param_2 = obj.pop()
# obj.increment(k,val)