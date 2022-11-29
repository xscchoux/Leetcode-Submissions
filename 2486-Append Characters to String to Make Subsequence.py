class Solution(object):
    def appendCharacters(self, s, t):
        """
        :type s: str
        :type t: str
        :rtype: int
        """
        left = 0
        
        for i in range(len(s)):
            if left < len(t) and s[i] == t[left]:
                left += 1
                
        if left != len(t):
            return len(t) - left
        
        else:
            return 0