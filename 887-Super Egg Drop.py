class Solution(object):
    def superEggDrop(self, k, n):
        """
        :type k: int
        :type n: int
        :rtype: int
        """
        
# Time complexity:O(k*n^2), TLE

#         dp = [[0]*(n+1) for _ in range(k+1)]
        
#         for i in range(1, n+1):
#             dp[1][i] = i

#         for egg in range(2, k+1):
#             for floor in range(1, n+1):
#                 if egg >= floor:
#                     dp[egg][floor] = dp[egg-1][floor]
#                 else:
#                     dp[egg][floor] = floor
#                     for s in range(1, floor):
#                         dp[egg][floor] = min(dp[egg][floor], max(dp[egg-1][s-1], dp[egg][floor-s])+1)
#         return dp[-1][-1]
    
# modified DP, O(k*n^2) TLE

#         dp = [[0]*(n+1) for _ in range(k+1)]
        
#         for i in range(1, n+1):
#             dp[1][i] = i

#         for egg in range(2, k+1):
#             for floor in range(1, n+1):
#                 if egg >= floor:
#                     dp[egg][floor] = dp[egg-1][floor]
#                 else:
#                     dp[egg][floor] = floor
#                     s = 1
#                     while (s<floor and dp[egg-1][s-1] < dp[egg][floor-s]):
#                         s+=1
#                     dp[egg][floor] = min(dp[egg][floor], max(dp[egg-1][s-1], dp[egg][floor-s])+1)
#         return dp[-1][-1]
                
# DP + binary search, O(k*n*logn), still TLE

#         dp = [[0]*(n+1) for _ in range(k+1)]
        
#         for i in range(1, n+1):
#             dp[1][i] = i

#         for egg in range(2, k+1):
#             for floor in range(1, n+1):
#                 if egg >= floor:
#                     dp[egg][floor] = dp[egg-1][floor]
#                 else:
#                     dp[egg][floor] = floor
#                     left, right = 1, floor
#                     while (left+1 < right):
#                         mid = left + (right-left)//2
#                         if dp[egg-1][mid-1] < dp[egg][floor-mid]:
#                             left = mid
#                         else:
#                             right = mid
#                     if dp[egg-1][left-1] >= dp[egg][floor-left]:
#                         dp[egg][floor] = min(dp[egg][floor], max(dp[egg-1][left-1], dp[egg][floor-left])+1)
#                     else:
#                         dp[egg][floor] = min(dp[egg][floor], max(dp[egg-1][right-1], dp[egg][floor-right])+1)
#         return dp[-1][-1]


# another DP, O(k*n)
# dp[i][j] : with i moves and j eggs, how many floors it can check
# When does dp[i][j] >= n ?

        dp = [[0]*(k+1) for _ in range(n+1)]
    
        for i in range(1, n+1):
            for j in range(1, k+1):
                dp[i][j] = 1 + dp[i-1][j-1] + dp[i-1][j]
            
            if dp[i][k] >= n:
                return i