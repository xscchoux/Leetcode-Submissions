class Solution(object):
    def numWays(self, n, k):
        """
        :type n: int
        :type k: int
        :rtype: int
        """
        if k == 0 or (k==1 and n>2):
            return 0
        
        same, diff = 0, k
        
        for i in range(1, n):
            tmp = diff
            diff = (diff+same)*(k-1)
            same = tmp
            
        return same + diff