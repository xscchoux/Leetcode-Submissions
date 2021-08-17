class Solution(object):
    def minWindow(self, s1, s2):
        """
        :type s1: str
        :type s2: str
        :rtype: str
        """
        i = j = 0           # index of s1 and s2
        res = ""
        start = 0
        prevLen = float('inf')
        
        while i < len(s1):
            if s1[i] == s2[j]:
                j += 1
                if j == len(s2):
                    j -= 1
                    ii = i
                    while j >= 0:
                        if s2[j] == s1[ii]:
                            j-=1
                        ii-=1
                    j = 0
                    ii += 1
                    if i - ii + 1 < prevLen:
                        res = s1[ii: i+1]
                        prevLen = i-ii+1
                    i = ii+1
                else:
                    i += 1
            else:
                i += 1
        return res