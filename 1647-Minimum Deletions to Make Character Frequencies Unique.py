class Solution(object):
    def minDeletions(self, s):
        """
        :type s: str
        :rtype: int
        """
        count = [0]*26
        for c in s:
            count[ord(c)-ord('a')] += 1
            
        res = 0
        usedFreq = set()
        
        for i in range(len(count)):
            while count[i] and count[i] in usedFreq:
                count[i] -= 1
                res += 1
            
            usedFreq.add(count[i])
        
        return res