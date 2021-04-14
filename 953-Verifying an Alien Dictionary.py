class Solution(object):
    def isAlienSorted(self, words, order):
        """
        :type words: List[str]
        :type order: str
        :rtype: bool
        """
        hmap = {c:i for i,c in enumerate(order)}
        
        for word1, word2 in zip(words, words[1:]):
            i=0
            while i < len(word1) and i < len(word2):
                if hmap[word1[i]] < hmap[word2[i]]:
                    break
                elif hmap[word1[i]] > hmap[word2[i]]:
                    return False
                else:
                    i+=1
            if i == len(word2) and word1[i:]:
                return False
            
        return True