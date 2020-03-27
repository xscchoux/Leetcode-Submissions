class Solution(object):
    def __init__(self):
        self.res = []
     
    def partition(self, s):
        """
        :type s: str
        :rtype: List[List[str]]
        """
# In the worst case (string is all equal characters, eg "aaaaaaa"), the DP solution depends on the previous solutions, which means the result space is

# f(n) = f(n-1) + f(n-2) + ... + f(1)
# f(n+1) = f(n) + f(n-1) + f(n-2) + ... + f(1)= 2*f(n)
# f(n+1)/f(n) = 2
# So, the time complexity is exponential O(2^n)

# DFS
        res = []
        n = len(s)
        def isPalindrome(s):
            left, right = 0, len(s)-1
            while left<right:
                if s[left] == s[right]:
                    left+=1
                    right-=1
                else:
                    return False
            return True
    
        def dfs(start, val):
            if start == n:
                res.append(val)
                return
            for i in range(start, n):
                currS = s[start:i+1]
                if isPalindrome(currS):
                    dfs(i+1, val+[currS])
        dfs(0, [])
        return res

# DFS + memoization

        res = []
        n = len(s)
        memo = {}
        def isPalindrome(s):
            left, right = 0, len(s)-1
            while left<right:
                if s[left] == s[right]:
                    left+=1
                    right-=1
                else:
                    return False
            return True

        def dfs(start):
            if start == n:
                return [[]]
            
            if s[start:] in memo:
                return memo[s[start:]]
            
            partitions = []
            for i in range(start, n):
                currS = s[start:i+1]

                if isPalindrome(currS):
                    subPartitions = dfs(i+1)
                    for partition in subPartitions:
                        partitions.append( [currS] + partition )
            memo[s[start:]] = partitions
            return partitions
            
        res = dfs(0)
        return res