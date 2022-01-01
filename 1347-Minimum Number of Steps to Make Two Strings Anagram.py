class Solution(object):
    def minSteps(self, s, t):
        """
        :type s: str
        :type t: str
        :rtype: int
        """
        chars = [0]*26
        res = 0
        
        for c in s:
            chars[ord(c) - ord('a')] += 1
        
        for x in t:
            chars[ord(x) - ord('a')] -= 1
        
        for val in chars:
            if val > 0:
                res += val
        
        return res