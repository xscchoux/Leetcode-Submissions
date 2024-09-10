class Node:
    def __init__(self, val):
        self.val = val
        self.prev = None
        self.next = None

class MyLinkedList:

    def __init__(self):
        self.head = Node(-1)
        self.tail = Node(-1)
        self.head.next = self.tail
        self.tail.prev = self.head

    def get(self, index: int) -> int:
        dummy = self.head
        for i in range(index+1):
            dummy = dummy.next # ith
            if dummy == self.tail:
                return -1
        
        return dummy.val

    def addAtHead(self, val: int) -> None:
        node = Node(val)
        nxt = self.head.next
        self.head.next = node
        node.next = nxt
        nxt.prev = node
        node.prev = self.head

    def addAtTail(self, val: int) -> None:
        node = Node(val)
        pre = self.tail.prev
        pre.next = node
        node.next = self.tail
        self.tail.prev = node
        node.prev = pre        

    def addAtIndex(self, index: int, val: int) -> None:
        dummy = self.head
        cnt = 0  # count of valid nodes
        for i in range(index+1):
            dummy = dummy.next # ith
            if dummy == self.tail:
                break
            cnt+=1
        if cnt == index:
            pre = self.tail.prev
            node = Node(val)
            pre.next = node
            node.next = self.tail
            self.tail.prev = node
            node.prev = pre   
        elif dummy != self.tail:
            pre = dummy.prev
            node = Node(val)
            pre.next = node
            node.next = dummy
            dummy.prev = node
            node.prev = pre

    def deleteAtIndex(self, index: int) -> None:
        dummy = self.head
        for i in range(index+1):
            dummy = dummy.next # ith
            if dummy == self.tail:
                return
        if dummy is not None:
            pre = dummy.prev
            nxt = dummy.next
            pre.next = nxt
            nxt.prev = pre

# Your MyLinkedList object will be instantiated and called as such:
# obj = MyLinkedList()
# param_1 = obj.get(index)
# obj.addAtHead(val)
# obj.addAtTail(val)
# obj.addAtIndex(index,val)
# obj.deleteAtIndex(index)