#O(N*2^N/C(N,k) ) for each query
class CombinationIterator(object):

    def __init__(self, characters, combinationLength):
        """
        :type characters: str
        :type combinationLength: int
        """
        self.N = len(characters)
        self.bitmask = (1<<self.N)-1
        self.k = combinationLength
        self.characters = characters
        
    def next(self):
        """
        :rtype: str
        """
        self.hasNext()
        res = []

        for i in range(self.N):
            if (self.bitmask >> (self.N-1-i)) & 1:
                res.append(self.characters[i])
        self.bitmask -= 1
        
        return "".join(res)

    def hasNext(self):
        """
        :rtype: bool
        """
        while self.bitmask and bin(self.bitmask).count("1") != self.k:
            self.bitmask-=1
        return self.bitmask != 0