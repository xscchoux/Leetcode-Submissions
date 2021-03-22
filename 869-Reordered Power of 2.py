from collections import Counter
class Solution(object):
    def reorderedPowerOf2(self, N):
        """
        :type N: int
        :rtype: bool
        """
        
        hmap = Counter(str(N))
        for i in range(30):
            if hmap == Counter(str(1<<i)):
                return True
        
        return False