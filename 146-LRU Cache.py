class DLinkedListNode:
    def __init__(self, k, v):
        self.next = None
        self.prev = None
        self.key = k
        self.val = v
    
#     def __str__(self):

#         return "[{}:{}] -->".format(self.key, self.val) + str(self.next)
    
    
class LRUCache(object):

    def __init__(self, capacity):
        """
        :type capacity: int
        """
        self.hmap = dict()
        self.capacity = capacity
        self.dummyhead = DLinkedListNode(0,0)
        self.dummytail = DLinkedListNode(0,0)
        self.dummyhead.next = self.dummytail
        self.dummytail.prev = self.dummyhead
    
    def removeNode(self, node):
        node.prev.next = node.next
        node.next.prev = node.prev
    
    def addNewNode(self, node):
        first = self.dummyhead.next
        node.prev = self.dummyhead
        self.dummyhead.next = node
        node.next = first
        first.prev = node
        
    def moveToFront(self, node):
        self.removeNode(node)
        self.addNewNode(node)
        
    def get(self, key):
        """
        :type key: int
        :rtype: int
        """
        if key not in self.hmap:
            return -1
        self.moveToFront(self.hmap[key])
        # print("Get {}".format(key)) 
        return self.hmap[key].val

    def put(self, key, value):
        """
        :type key: int
        :type value: int
        :rtype: None
        """
        if key in self.hmap:
            self.hmap[key].val = value
            self.moveToFront(self.hmap[key])
        else:
            newNode = DLinkedListNode(key, value)
            self.hmap[key] = newNode
            self.addNewNode(newNode)
            if len(self.hmap) > self.capacity:
                del self.hmap[self.dummytail.prev.key]
                self.removeNode(self.dummytail.prev)

        # print("Put {},{}".format(key,value)+str(self.dummyhead))

# Your LRUCache object will be instantiated and called as such:
# obj = LRUCache(capacity)
# param_1 = obj.get(key)
# obj.put(key,value)