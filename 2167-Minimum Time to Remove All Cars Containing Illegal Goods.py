class Solution(object):
    def minimumTime(self, s):
        """
        :type s: str
        :rtype: int
        """
        right = [0]*(len(s)+1)
        
        for i in range(len(s)-1, -1, -1):
            if s[i] == '1':
                right[i] = min(right[i+1] + 2, len(s)-i)
            else:
                right[i] = right[i+1]
                
        left = 0
        res = len(s)
        for j in range(len(s)):
            if s[j] == '1':
                left = min(left + 2, j+1)
            res = min(res, left + right[j+1])
            
        return res