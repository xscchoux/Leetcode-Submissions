class Block:
    def __init__(self, value):
        self.val = value
        self.prev = None
        self.next = None
        self.elements = set()
    def remove(self):
        self.prev.next = self.next
        self.next.prev = self.prev
        self.prev = None
        self.next = None
    def insertAfter(self, node):
        tmp = self.next
        self.next = node
        node.next = tmp
        tmp.prev = node
        node.prev = self

class AllOne:

    def __init__(self):
        self.head = Block(-1)
        self.tail = Block(-1)
        self.head.next = self.tail
        self.tail.prev = self.head
        self.mapping = dict()

    def inc(self, key: str) -> None:
        if key in self.mapping:
            block = self.mapping[key]
            if block.next.val != block.val + 1:
                newBlock = Block(block.val+1)
                newBlock.elements.add(key)
                block.insertAfter(newBlock)
            else:
                newBlock = block.next
                newBlock.elements.add(key)
            self.mapping[key] = newBlock
            # remove original
            block.elements.remove(key)
            if not block.elements:
                block.remove()
        else:
            if self.head.next.val != 1:
                newBlock = Block(1)
                newBlock.elements.add(key)
                self.head.insertAfter(newBlock)
            else:
                newBlock = self.head.next
                newBlock.elements.add(key)
            self.mapping[key] = newBlock

    def dec(self, key: str) -> None:
        # It is guaranteed that key exists in the data structure before the decrement
        block = self.mapping[key]
        block.elements.remove(key)
        if block.val == 1:
            del self.mapping[key]
        else:
            if block.val == block.prev.val + 1:
                newBlock = block.prev
                newBlock.elements.add(key)
            else:
                newBlock = Block(block.val-1)
                newBlock.elements.add(key)
                block.prev.insertAfter(newBlock)
            self.mapping[key] = newBlock
        if not block.elements:
            block.remove()

    def getMaxKey(self) -> str:
        if not self.tail.prev.elements:
            return ""
        return next(iter(self.tail.prev.elements))

    def getMinKey(self) -> str:
        if not self.head.next.elements:
            return ""
        return next(iter(self.head.next.elements))