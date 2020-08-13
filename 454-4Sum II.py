class Solution(object):
    def fourSumCount(self, A, B, C, D):
        """
        :type A: List[int]
        :type B: List[int]
        :type C: List[int]
        :type D: List[int]
        :rtype: int
        """
        res = 0
        hmap = dict()
        for a in A:
            for b in B:
                hmap[a+b] = hmap.get(a+b, 0) + 1

        for c in C:
            for d in D:
                if -(c+d) in hmap:
                    res += hmap[-(c+d)]
        return res