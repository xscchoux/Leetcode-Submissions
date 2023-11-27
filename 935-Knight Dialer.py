class Solution(object):
    def knightDialer(self, n):
        """
        :type n: int
        :rtype: int
        """
# first try        

        if n == 1:
            return 10
        
        kMod = 1000000007
        hmap = {0:(4, 6), 1:(6, 8), 2:(7, 9), 3:(4, 8), 4:(0, 3, 9), 6:(0, 1, 7), 7:(2, 6), 8:(1, 3), 9:(2, 4)}
        
        
        dp = [ [0]*(n+1) for _ in range(10)]  # dp[num][steps left] = # of paths
        for i in range(10):
            dp[i][1] = 1
        
        for step in range(2, n+1):
            for num in (0, 1, 2, 3, 4 ,6, 7, 8, 9):
                for nxt in hmap[num]:
                    dp[nxt][step] = (dp[nxt][step] + dp[num][step-1])%kMod
                    
        return sum(x[n] for x in dp)%kMod
    
    
        
# faster method
        kMod = 1000000007
        x1=x2=x3=x4=x5=x6=x7=x8=x9=x0=1
        for i in range(2, n+1):
            newX1 = (x6 + x8)%kMod
            newX2 = (x7 + x9)%kMod
            newX3 = (x4 + x8)%kMod
            newX4 = (x0 + x3 + x9)%kMod
            newX5 = 0
            newX6 = (x0 + x1 + x7)%kMod
            newX7 = (x2 + x6)%kMod
            newX8 = (x1 + x3)%kMod
            newX9 = (x2 + x4)%kMod
            newX0 = (x4 + x6)%kMod
            x1, x2, x3, x4, x5, x6, x7, x8, x9, x0 = newX1, newX2, newX3, newX4, newX5, newX6, newX7, newX8, newX9, newX0
        
        return (x1+x2+x3+x4+x5+x6+x7+x8+x9+x0)%kMod


# Top-down, significant performance improvement can be achieved by moving the dp() function outside of the Solution class

hmap = {0:[4, 6], 1:[6, 8], 2:[7, 9], 3:[4, 8], 4:[0, 3, 9], 5:[], 6:[0, 1, 7], 7:[2, 6], 8:[1, 3], 9:[2, 4]}
kMod = 10**9+7

@cache
def dp(idx, num):
    if idx == 1:
        return 1
    tot = 0
    for nxt in hmap[num]:
        tot = (tot + dp(idx-1, nxt))%kMod
    return tot

class Solution:
    def knightDialer(self, n: int) -> int:
        res = 0
        for num in range(10):
            res = (res + dp(n, int(num)))%kMod
        
        return res