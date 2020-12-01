from collections import defaultdict
class Solution(object):
    def shortestDistance(self, words, word1, word2):
        """
        :type words: List[str]
        :type word1: str
        :type word2: str
        :rtype: int
        """
        i1 = -1
        i2 = -1
        res = len(words)
        for i in range(len(words)):
            if words[i] == word1:
                i1 = i
            elif words[i] == word2:
                i2 = i
                
            if i1 != -1 and i2 != -1:
                res = min(res, abs(i1-i2))
        
        return res