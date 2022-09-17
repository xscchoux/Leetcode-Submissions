class Solution(object):
    def numDifferentIntegers(self, word):
        """
        :type word: str
        :rtype: int
        """
        s = "".join([c if c.isdigit() else " " for c in word])
        return len(set(map(int, s.split())))