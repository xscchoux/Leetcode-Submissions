class Solution(object):
    def minimumSwap(self, s1, s2):
        """
        :type s1: str
        :type s2: str
        :rtype: int
        """
        xCount = 0
        yCount = 0
        
        for a, b in zip(s1, s2):
            if a != b:
                if a == 'x':
                    xCount += 1
                else:
                    yCount += 1
        
        if ( (xCount + yCount) & 1) == 1:
            return -1
        
        return xCount//2 + yCount//2 + 2*(xCount&1)