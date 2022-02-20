class FreqStack(object):

    def __init__(self):
        self.maxFreq = 0
        self.counter = collections.defaultdict(int)
        self.freqGroup = collections.defaultdict(list)

    def push(self, val):
        """
        :type val: int
        :rtype: None
        """
        self.counter[val] += 1
        if self.counter[val] > self.maxFreq:
            self.maxFreq = self.counter[val]
        self.freqGroup[self.counter[val]].append(val)

    def pop(self):
        """
        :rtype: int
        """
        x = self.freqGroup[self.maxFreq].pop()
        self.counter[x] -= 1
        if not self.freqGroup[self.maxFreq]:
            self.maxFreq -= 1
            
        return x

# Your FreqStack object will be instantiated and called as such:
# obj = FreqStack()
# obj.push(val)
# param_2 = obj.pop()