class Solution(object):
    def findIntegers(self, n):
        """
        :type n: int
        :rtype: int
        """
# A very tricky problem
# dp[k] gives the count of such binary numbers with i bits

# Example1: n = 1001001

# calculate: 1.  000000 (from)  add dp[6]
#                111111 (to)

#            2. 1000111 (from)  add dp[3]
#               1000000 (to)

#            3. 1001000         add dp[0]

#            return dp[6] + dp[3] + dp[0] + 1 (the number n itself)


# Example2: n = 1001101

# calculate: 1.  000000 (from)  add dp[6]
#                111111 (to)

#            2. 1000111 (from)  add dp[3]
#               1000000 (to)

#            3. 1001011 (from)  add dp[2]
#               1001000 (to)

#            4. break...since we found two consecutive 1s

#            return dp[6] + dp[3] + dp[2]

    
        dp = [0]*32
        dp[0] = 1
        dp[1] = 2
        
        for i in range(2, 32):
            dp[i] = dp[i-1] + dp[i-2]
        
        k = 31
        res = 0
        pre = 0
        while k >= 0:
            if n & (1<<k):
                res += dp[k]
                if pre == 1:
                    return res
                pre = 1
            else:
                pre = 0
            
            k-=1
        return res+1 # plus the number itself