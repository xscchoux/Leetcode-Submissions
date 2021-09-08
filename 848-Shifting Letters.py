class Solution(object):
    def shiftingLetters(self, s, shifts):
        """
        :type s: str
        :type shifts: List[int]
        :rtype: str
        """
        s = list(s)
        tot = 0
        for i in range(len(s)-1, -1, -1):
            tot += shifts[i]
            s[i] = chr( 97 + (ord(s[i]) + tot - 97)%26 )
        return "".join(s)