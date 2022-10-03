class Solution(object):
    def equalFrequency(self, word):
        """
        :type word: str
        :rtype: bool
        """
        tot = collections.Counter(word)
        
        for c in word:
            tot[c] -= 1
            if not tot[c]:
                del tot[c]

            if len(set(tot.values())) == 1:
                return True
            tot[c] += 1
        
        return False