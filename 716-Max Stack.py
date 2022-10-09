class MaxStack(object):

    def __init__(self):
        """
        initialize your data structure here.
        """
        self.stack = [[float('-inf'), float('-inf')]]

    def push(self, x):
        """
        :type x: int
        :rtype: None
        """
        if not self.stack:
            self.stack.append([x,x])
        else:
            if x > self.stack[-1][1]:
                self.stack.append([x, x])
            else:
                self.stack.append([x, self.stack[-1][1]])

    def pop(self):
        """
        :rtype: int
        """
        return self.stack.pop()[0]

    def top(self):
        """
        :rtype: int
        """
        return self.stack[-1][0]

    def peekMax(self):
        """
        :rtype: int
        """
        return self.stack[-1][1]

    def popMax(self):
        """
        :rtype: int
        """
        val, maxValue = self.stack.pop()
        temp = []
        
        while val != maxValue:
            temp.append(val)
            val, _ = self.stack.pop()
        
        for x in reversed(temp):
            self.push(x)
            
        return maxValue
        

# Your MaxStack object will be instantiated and called as such:
# obj = MaxStack()
# obj.push(x)
# param_2 = obj.pop()
# param_3 = obj.top()
# param_4 = obj.peekMax()
# param_5 = obj.popMax()



from sortedcontainers import SortedList
class MaxStack(object):

    def __init__(self):
        self.cnt = 0
        self.maxStack = SortedList()
        self.stack = SortedList()

    def push(self, x):
        """
        :type x: int
        :rtype: None
        """
        self.stack.add((self.cnt, x))
        self.maxStack.add((x, self.cnt))
        self.cnt += 1

    def pop(self):
        """
        :rtype: int
        """
        count, val = self.stack.pop()
        self.maxStack.remove((val, count))
        return val
        
    def top(self):
        """
        :rtype: int
        """
        return self.stack[-1][1]

    def peekMax(self):
        """
        :rtype: int
        """
        return self.maxStack[-1][0]        

    def popMax(self):
        """
        :rtype: int
        """
        val, count = self.maxStack.pop()
        self.stack.remove((count, val))
        return val

# Your MaxStack object will be instantiated and called as such:
# obj = MaxStack()
# obj.push(x)
# param_2 = obj.pop()
# param_3 = obj.top()
# param_4 = obj.peekMax()
# param_5 = obj.popMax()