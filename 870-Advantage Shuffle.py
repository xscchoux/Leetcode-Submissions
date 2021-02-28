class Solution(object):
    def advantageCount(self, A, B):
        """
        :type A: List[int]
        :type B: List[int]
        :rtype: List[int]
        """
        Bsorted = sorted([(b, i) for i, b in enumerate(B)])
        res = [None]*len(A)
        index = 0
        
        for a in sorted(A):
            if a > Bsorted[index][0]:
                res[Bsorted[index][1]] = a
                index += 1
            else:
                res[Bsorted.pop()[1]] = a
        
        return res