class AutocompleteSystem:

    def __init__(self, sentences: List[str], times: List[int]):
        self.prefix = []
        self.matched = []
        self.freq = defaultdict(int)
        for s, t in zip(sentences, times):
            self.freq[s] += t

    def input(self, c: str) -> List[str]:
        if c == "#":
            self.freq["".join(self.prefix)] += 1
            self.prefix = []
            self.matched = []
            return []
        
        if not self.prefix:
            self.matched = [s for s in self.freq.keys() if s[0] == c]
            self.matched.sort(key = lambda x:(-self.freq[x], x))
        else:
            length = len(self.prefix)
            self.matched = [s for s in self.matched if len(s) > length and s[length] == c]
            
        self.prefix.append(c)
        
        return self.matched[:3]


# Your AutocompleteSystem object will be instantiated and called as such:
# obj = AutocompleteSystem(sentences, times)
# param_1 = obj.input(c)