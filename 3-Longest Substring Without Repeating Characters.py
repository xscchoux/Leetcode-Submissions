class Solution(object):
    def lengthOfLongestSubstring(self, s):
        """
        :type s: str
        :rtype: int
        """
    
        lastPos = dict()
        start = 0
        res = 0
        for i in range(len(s)):
            if s[i] in lastPos and lastPos[s[i]] >=start:   # must know why lastPos[s[i]] >=start, try the input 'abba'
                start = lastPos[s[i]]+1
            lastPos[s[i]] = i
            
            if i-start+1 > res:
                res = i-start+1
                
        return res