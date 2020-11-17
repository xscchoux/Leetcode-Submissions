class Solution(object):
    def numOfWays(self, n):
        """
        :type n: int
        :rtype: int
        """
# https://www.youtube.com/watch?v=uId0P2zAHKk&ab_channel=LeadCoding
        same = diff = 6
        modulo = 10**9 + 7
        
        for i in range(1,n):
            tmp = same
            same = (2*diff + 3*tmp)%modulo
            diff = (2*tmp + 2*diff)%modulo
        
        return (same+diff)%modulo