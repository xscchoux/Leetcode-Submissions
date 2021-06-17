class Solution(object):
    def minWindow(self, s, t):
        """
        :type s: str
        :type t: str
        :rtype: str
        """
        numChar = len(t)
        start = 0
        countDict = collections.Counter(t)
        count = 0
        resRange = (0, float('inf'))
        
        
        for i in range(len(s)):
            countDict[s[i]] -= 1
            if countDict[s[i]] >= 0:
                count += 1
                
            while count == numChar:
                countDict[s[start]] += 1
                if countDict[s[start]] > 0:
                    count -= 1
                if resRange[1]-resRange[0] > i-start:
                    resRange = (start, i)
                start += 1
            
        return '' if resRange[1] == float('inf') else s[resRange[0]:resRange[1]+1]