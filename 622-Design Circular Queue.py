class Node:
    def __init__(self, value, nxt = None):
        self.val = value
        self.next = nxt
    
class MyCircularQueue(object):

    def __init__(self, k):
        """
        :type k: int
        """
        self.limit = k
        self.head = None
        self.tail = None
        self.count = 0
        
    def enQueue(self, value):
        """
        :type value: int
        :rtype: bool
        """
        if self.count == self.limit:
            return False
        
        if not self.head:
            self.head = Node(value)
            self.tail = self.head
        else:
            self.tail.next = Node(value)
            self.tail = self.tail.next
        self.count += 1
        return True

    def deQueue(self):
        """
        :rtype: bool
        """
        if not self.count:
            return False
        self.head = self.head.next
        self.count -= 1
        return True

    def Front(self):
        """
        :rtype: int
        """
        if not self.count:
            return -1
        return self.head.val

    def Rear(self):
        """
        :rtype: int
        """
        if not self.count:
            return -1
        return self.tail.val

    def isEmpty(self):
        """
        :rtype: bool
        """
        return not self.count

    def isFull(self):
        """
        :rtype: bool
        """
        return self.count == self.limit


# Your MyCircularQueue object will be instantiated and called as such:
# obj = MyCircularQueue(k)
# param_1 = obj.enQueue(value)
# param_2 = obj.deQueue()
# param_3 = obj.Front()
# param_4 = obj.Rear()
# param_5 = obj.isEmpty()
# param_6 = obj.isFull()