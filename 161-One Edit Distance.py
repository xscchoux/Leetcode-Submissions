class Solution(object):
    def isOneEditDistance(self, s, t):
        """
        :type s: str
        :type t: str
        :rtype: bool
        """
        lengthS, lengthT = len(s), len(t)
        if abs(lengthS - lengthT) > 1 or s == t:
            return False
        
        findDiff = False
        p1 = p2 = 0
        
        while p1 < lengthS and p2 < lengthT:
            if s[p1] != t[p2]:
                if findDiff:
                    return False
                findDiff = True
                if lengthS > lengthT:
                    p2-=1
                if lengthT > lengthS:
                    p1-=1
            p1+=1
            p2+=1
        
        return True