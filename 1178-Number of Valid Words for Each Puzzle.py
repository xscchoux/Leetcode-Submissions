class Solution(object):
    def findNumOfValidWords(self, words, puzzles):
        """
        :type words: List[str]
        :type puzzles: List[str]
        :rtype: List[int]
        """
# O(50*10^5 + 7*10^4)
        def toBit(string):
            bitmask = 0
            for w in string:
                bitmask = bitmask | (1<<(ord(w)-ord('a')))
            return bitmask
        
        wordBitDict = collections.defaultdict(int)
        
        for word in words:
            wordBitDict[toBit(word)] += 1
        
        res = []
        
        for puzzle in puzzles:
            puzzleBit = toBit(puzzle)
            firstBit = 1<<(ord(puzzle[0])-ord('a'))
            count = 0
            tmp = puzzleBit
            while tmp > 0:   # iterate over all subsets
                if firstBit & tmp:
                    count += wordBitDict[tmp]
                tmp = (tmp-1) & puzzleBit
            res.append(count)       
        
        return res