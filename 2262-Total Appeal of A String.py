class Solution(object):
    def appealSum(self, s):
        """
        :type s: str
        :rtype: int
        """
# https://www.youtube.com/watch?v=mvFIQmYiBhQ
# O(n)
        n = len(s)
        hmap = dict()
        res = 0
        for i, c in enumerate(s):
            if c in hmap:
                res += (i - hmap[c])*(n-i)
            else:
                res += (i+1)*(n-i)
            hmap[c] = i        
            
        return res