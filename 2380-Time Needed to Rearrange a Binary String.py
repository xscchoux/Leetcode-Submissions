class Solution(object):
    def secondsToRemoveOccurrences(self, s):
        """
        :type s: str
        :rtype: int
        """
# O(n^2)
#         res = 0
#         while "01" in s:
#             s = s.replace('01', '10')
#             res+=1
            
#         return res
        
        
# https://leetcode.com/problems/time-needed-to-rearrange-a-binary-string/discuss/2454262/DP-vs.-Brute-Force
        zeros = 0
        res = 0 # seconds needed to move current 1 to the desired position
        
        for i, c in enumerate(s):
            if c == "0":
                zeros += 1
            elif zeros > 0:
                res = max(zeros, res+1)
        
        return res