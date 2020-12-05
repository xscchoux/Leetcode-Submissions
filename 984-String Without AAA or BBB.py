class Solution(object):
    def strWithout3a3b(self, A, B):
        """
        :type A: int
        :type B: int
        :rtype: str
        """
        diff = A-B
        res = []
        
        if diff > 0:
            group = min(diff, B)
            res += ["aab"]*group
            A -= 2*group
            B -= group
        elif diff < 0:
            group = min(-diff, A)
            res += ["bba"]*group
            B -= 2*group
            A -= group
        
        remain = min(A,B)
        res += ["ab"]*remain
        A-=remain
        B-=remain
        
        res += ["a"]*A + ["b"]*B
            
        return "".join(res)