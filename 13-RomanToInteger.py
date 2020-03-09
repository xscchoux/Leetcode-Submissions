class Solution(object):
    def romanToInt(self, s):
        """
        :type s: str
        :rtype: int
        """
        double = {'IV':4, 'IX':9, 'XL':40, 'XC':90, 'CD':400, 'CM':900 }
        single = {'I':1, 'V':5, 'X':10, 'L':50, 'C':100, 'D':500, 'M':1000 }
        
        i = 0
        res = 0
        while i<len(s):
            if i<len(s)-1 and s[i:i+2] in double:
                res+=double[s[i:i+2]]
                i+=2
            else:
                res+=single[s[i:i+1]]
                i+=1
                
        return res