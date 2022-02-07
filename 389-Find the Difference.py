class Solution(object):
    def findTheDifference(self, s, t):
        """
        :type s: str
        :type t: str
        :rtype: str
        """
        ch = 0
        
        for char in s:
            ch ^= ord(char)
        
        for char in t:
            ch ^= ord(char)
            
        return chr(ch)