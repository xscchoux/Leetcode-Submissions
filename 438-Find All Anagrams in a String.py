from collections import Counter
class Solution(object):
    def findAnagrams(self, s, p):
        """
        :type s: str
        :type p: str
        :rtype: List[int]
        """
        if len(s) < len(p):
            return []
        pMap = Counter(p)
        sMap = Counter(s[0:len(p)])
        res = []
        for i in range(len(s)-len(p)):
            if pMap == sMap:
                res.append(i)                
            sMap[s[i+len(p)]] += 1
            sMap[s[i]] -= 1
            if not sMap[s[i]]:
                del sMap[s[i]]
        
        if pMap == sMap:
            res.append(len(s)-len(p))
        
        return res