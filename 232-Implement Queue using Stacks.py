class MyQueue:

    def __init__(self):
        self.stk1 = []
        self.stk2 = []

    def prepare(self):
        if not self.stk2:
            while self.stk1:
                self.stk2.append(self.stk1.pop())        
        
    def push(self, x: int) -> None:
        self.stk1.append(x)

    def pop(self) -> int:
        self.prepare()
        return self.stk2.pop()
        
    def peek(self) -> int:
        self.prepare()
        return self.stk2[-1]

    def empty(self) -> bool:
        
        return len(self.stk1) == 0 and len(self.stk2) == 0


# Your MyQueue object will be instantiated and called as such:
# obj = MyQueue()
# obj.push(x)
# param_2 = obj.pop()
# param_3 = obj.peek()
# param_4 = obj.empty()