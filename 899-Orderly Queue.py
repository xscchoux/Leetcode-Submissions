class Solution(object):
    def orderlyQueue(self, s, k):
        """
        :type s: str
        :type k: int
        :rtype: str
        """
        N = len(s)
        
        if k == 1:
            return min([s[i:]+s[:i] for i in range(N)])
        else:
            return "".join(sorted(s))