# use two Queues

import sys
if sys.version > '3':
	import queue as Queue
else:
	import Queue
# Queue has two major methods: put and get
class MyStack(object):

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.queue1 = Queue.Queue()
        self.queue2 = Queue.Queue()
        
    def push(self, x):
        """
        Push element x onto stack.
        :type x: int
        :rtype: None
        """
        self.queue1.put(x)

    def pop(self):
        """
        Removes the element on top of the stack and returns that element.
        :rtype: int
        """
        while self.queue1.qsize() > 1:
            self.queue2.put(self.queue1.get())
        res = self.queue1.get()
        self.queue1, self.queue2 = self.queue2, self.queue1
        return res
    
    def top(self):
        """
        Get the top element.
        :rtype: int
        """
        while self.queue1.qsize() > 1:
            self.queue2.put(self.queue1.get())
        res = self.queue1.get()
        self.queue2.put(res)
        self.queue1, self.queue2 = self.queue2, self.queue1
        return res

    def empty(self):
        """
        Returns whether the stack is empty.
        :rtype: bool
        """
        return self.queue1.empty()


# Your MyStack object will be instantiated and called as such:
# obj = MyStack()
# obj.push(x)
# param_2 = obj.pop()
# param_3 = obj.top()
# param_4 = obj.empty()