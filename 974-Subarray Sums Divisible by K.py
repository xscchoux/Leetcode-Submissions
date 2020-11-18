from collections import defaultdict
class Solution(object):
    def subarraysDivByK(self, A, K):
        """
        :type A: List[int]
        :type K: int
        :rtype: int
        """
        preSum = [0]
        hmap = defaultdict(int)
        hmap[0] = 1
        
        for a in A:
            preSum.append( (preSum[-1] + a)%K )
            hmap[preSum[-1]] += 1
            
        return sum([value*(value-1)/2 for value in hmap.values()])