class Solution(object):
    def validUtf8(self, data):
        """
        :type data: List[int]
        :rtype: bool
        """
# https://www.youtube.com/watch?v=0s4M9Y1ue5o
        seqLen = 0
        
        for d in data:
            if seqLen == 0:
                if d >> 7 == 0:
                    seqLen = 0    
                elif d >> 5 == 6:
                    seqLen = 1
                elif d >> 4 == 14:
                    seqLen = 2
                elif d >> 3 == 30:
                    seqLen = 3
                else:
                    return False
            else:
                if d >> 6 != 2:
                    return False
                seqLen -= 1
        
        return seqLen == 0