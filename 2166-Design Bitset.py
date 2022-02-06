class Bitset:

    def __init__(self, size: int):
        self.num = 0
        self.N = size
        self.ones = 0

    def fix(self, idx: int) -> None:
        if not (self.num & (1<<(self.N-1-idx))):
            self.num = self.num ^ (1<<(self.N-1-idx))
            self.ones += 1

    def unfix(self, idx: int) -> None:
        if (self.num & (1<<(self.N-1-idx))):
            self.num = self.num ^ (1<<(self.N-1-idx))
            self.ones -= 1
        
    def flip(self) -> None:
        self.ones = self.N - self.ones
        self.num = self.num^((1<<self.N)-1)       
        
    def all(self) -> bool:
        if self.ones == self.N:
            return True
        return False

    def one(self) -> bool:
        if self.ones:
            return True
        return False

    def count(self) -> int:
        return self.ones

    def toString(self) -> str:
        res = bin(self.num)[2:]
        return res.zfill(self.N)
             

# Your Bitset object will be instantiated and called as such:
# obj = Bitset(size)
# obj.fix(idx)
# obj.unfix(idx)
# obj.flip()
# param_4 = obj.all()
# param_5 = obj.one()
# param_6 = obj.count()
# param_7 = obj.toString()