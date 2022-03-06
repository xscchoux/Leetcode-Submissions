class Solution(object):
    def countOrders(self, n):
        """
        :type n: int
        :rtype: int
        """

# https://www.youtube.com/watch?v=Q0dVILwk-dY
        res = 1
        kMod = 1000000007
        
        for i in range(2, n+1):
            canPut = 2*(i-1) + 1
            res = (res*canPut*(canPut+1)//2)%kMod
            
        return res