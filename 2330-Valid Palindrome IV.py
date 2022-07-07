class Solution(object):
    def makePalindrome(self, s):
        """
        :type s: str
        :rtype: bool
        """
        left, right = 0, len(s)-1
        res = 0
        
        while left < right:
            if s[left] != s[right]:
                res += 1
            left += 1
            right -= 1
            if res > 2:
                return False
            
        return True