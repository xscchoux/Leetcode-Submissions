from collections import deque
class Solution(object):
    def isInterleave(self, s1, s2, s3):
        """
        :type s1: str
        :type s2: str
        :type s3: str
        :rtype: bool
        """
        
# DP, O(m*n)
        if len(s1) + len(s2) != len(s3):
            return False
        
        
        n1, n2 = len(s1), len(s2)
        
        dp = [[False]*(n2+1) for _ in range(n1+1)]
        dp[0][0] = True
        
        for j in range(1, n2+1):
            dp[0][j] = dp[0][j-1] and s2[j-1] == s3[j-1]
        
        for i in range(1, n1+1):
            dp[i][0] = dp[i-1][0] and s1[i-1] == s3[i-1]
            
        for i in range(1, n1+1):
            for j in range(1, n2+1):
                dp[i][j] = (s1[i-1] == s3[i+j-1] and dp[i-1][j]) or (s2[j-1] == s3[i+j-1] and dp[i][j-1])
        
        return dp[-1][-1]
        
# DFS + memo,O(m*n)
        if len(s1) + len(s2) != len(s3):
            return False
        
        n1, n2, n3 = len(s1), len(s2), len(s3)
        memo = set()
        
        def helper(i, j, k):
            if i+j == n3:
                return True
            if (i, j) in memo:
                return False
            
            res = False
            if i<n1 and s1[i] == s3[k]:
                res = helper(i+1, j, k+1)
            if j<n2 and s2[j] == s3[k]:
                res = res or helper(i, j+1, k+1)
            
            if res:
                return True
            else:
                memo.add((i,j))
                return False
        
        return helper(0, 0, 0)
            
# BFS, O(m*n)
        if len(s1) + len(s2) != len(s3):
            return False
    
        queue = deque([(0,0,0)])
        n1, n2, n3 = len(s1), len(s2), len(s3)
        used = set()
        
        while queue:
            for _ in range(len(queue)):
                i, j, k = queue.popleft()
                if k == n3:
                    return True
                if i<n1 and s1[i] == s3[k]:
                    if (i+1,j) not in used:
                        used.add((i+1,j))
                        queue.append((i+1,j,k+1))
                if j<n2 and s2[j] == s3[k]:
                    if (i,j+1) not in used:
                        used.add((i,j+1))
                        queue.append((i,j+1,k+1))
        return False
        