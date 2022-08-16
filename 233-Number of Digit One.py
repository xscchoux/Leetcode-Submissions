class Solution(object):
    def countDigitOne(self, n):
        """
        :type n: int
        :rtype: int
        """
# https://www.youtube.com/watch?v=QlMyXlhI3Ic
# O(N)
        s = str(n)
        N = len(s)
        count = 0
        
        for i in range(1, N+1):
            left = n//pow(10, i)
            count += left*pow(10, i-1)
            
            if int(s[N-i]) > 1:
                count += pow(10, i-1)
            elif int(s[N-i]) == 1:
                count += n%pow(10, i-1) + 1
        return count