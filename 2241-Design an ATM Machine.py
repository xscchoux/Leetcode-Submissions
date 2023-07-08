class ATM:

    def __init__(self):
        self.notes = [0]*5
        self.dict = {4:500, 3:200, 2:100, 1:50, 0:20}

    def deposit(self, banknotesCount: List[int]) -> None:
        for i in range(5):
            self.notes[i] += banknotesCount[i]
            
    def withdraw(self, amount: int) -> List[int]:      
        used = [0]*5
        
        for i in range(4, -1, -1):
            if amount < self.dict[i]:
                continue
            take = min(amount//self.dict[i], self.notes[i])
            amount -= take*self.dict[i]
            used[i] = take
            
        if amount == 0:
            for i in range(len(self.notes)):
                self.notes[i] -= used[i]
            return used
        else:
            return [-1]

# Your ATM object will be instantiated and called as such:
# obj = ATM()
# obj.deposit(banknotesCount)
# param_2 = obj.withdraw(amount)