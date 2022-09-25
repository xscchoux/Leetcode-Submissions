class Solution(object):
    def repeatedStringMatch(self, a, b):
        """
        :type a: str
        :type b: str
        :rtype: int
        """
        q, remainder = divmod(len(b), len(a))
        if remainder:
            q += 1
        
        newS = q*a
        
        if b in newS:
            return q
        elif b in newS+a:
            return q+1
        elif b in newS+a+a:
            return q+2
        else:
            return -1