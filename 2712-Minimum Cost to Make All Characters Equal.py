class Solution:
    def minimumCost(self, s: str) -> int: 
# prefix and suffix sum
        N = len(s)
        leftPrefix = [0]*N  # cost to make s[:i] bits equal to s[i]
        
        for i in range(1, N):
            if s[i] != s[i-1]:
                leftPrefix[i] = leftPrefix[i-1] + i
            else:
                leftPrefix[i] = leftPrefix[i-1]
        
        tot = 0
        res = leftPrefix[-1]
        
        for i in range(N-2, -1, -1):
            if s[i] != s[i+1]:
                tot += (N-i-1)
            res = min(res, tot + leftPrefix[i])
        
        return res
    
# O(1) greedy, hard to come up with
# check left side: 1, 2, 3, ...
# check right side: N-1, N-2, N-3, ...

        N = len(s)
        res = 0
        for i in range(1, N):
            if s[i] != s[i-1]:
                res += min(i, N-i)
        
        return res