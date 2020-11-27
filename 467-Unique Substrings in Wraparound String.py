class Solution(object):
    def findSubstringInWraproundString(self, p):
        """
        :type p: str
        :rtype: int
        """
        endAt = [0]*26
        length = 0
        
        for ind, char in enumerate(p):
            if ind != 0 and ( ord(char) == ord(p[ind-1]) + 1 or ord(char) == ord(p[ind-1]) - 25 ):
                length += 1
            else:
                length = 1 
            endAt[ord(char) - ord('a')] = max(endAt[ord(char) - ord('a')], length)
        return sum(endAt)