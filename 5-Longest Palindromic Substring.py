class Solution(object):
    def longestPalindrome(self, s):
        """
        :type s: str
        :rtype: str
        """
        if not s:
            return ""
        res = 0
        
        def expandAroundCenter(left, right):
            l, r = left, right
            while l >= 0 and r < len(s) and s[l] == s[r]:
                l -= 1
                r += 1
            return r-l-1
        
        start, end = 0, 0
        for i in range(len(s)):
            len1 = expandAroundCenter(i,i)
            len2 = expandAroundCenter(i,i+1)
            length = max(len1, len2)
            if length > res:
                start = i - (length-1)//2
                end = i + length//2
                res = length
        return s[start:end+1]