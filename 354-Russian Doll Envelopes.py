class Solution(object):
    def maxEnvelopes(self, envelopes):
        """
        :type envelopes: List[List[int]]
        :rtype: int
        """
# brute force, O(n^2), TLE

#         envelopes.sort(key = lambda x: (x[0],x[1]))
#         N = len(envelopes)
#         dp = [1]*N
        
#         for i in range(N):
#             for j in range(i):
#                 if envelopes[i][0] > envelopes[j][0] and envelopes[i][1] > envelopes[j][1]:
#                     dp[i] = max(dp[i], dp[j]+1)
        
#         return max(dp)


# Sort + Longest Increasig Subsequence
# Time complexity: O(NlogN)
# Space complexity: O(N)

        envelopes.sort(key = lambda x:(x[0], -x[1]))
        N = len(envelopes)
        dp = []
        
        for i in range(N):
            if not dp or envelopes[i][1] > dp[-1]:
                dp.append(envelopes[i][1])
            else:
                left, right = 0, len(dp)-1
                while left + 1 < right:
                    mid = left + (right-left)//2
                    if envelopes[i][1] <= dp[mid]:
                        right = mid
                    else:
                        left = mid
                if dp[left] >= envelopes[i][1]:
                    dp[left] = envelopes[i][1]
                else:
                    dp[right] = envelopes[i][1]
        
        return len(dp)