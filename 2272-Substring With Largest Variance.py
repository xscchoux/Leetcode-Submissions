class Solution(object):
    def largestVariance(self, s):
        """
        :type s: str
        :rtype: int
        """
# https://leetcode.com/problems/substring-with-largest-variance/discuss/2038438/Python3-using-max-sum-subarray-with-explanation
        def Kadane(arr):
            found=False
            running = 0
            res = 0
            for x in arr:
                if x<0:
                    found=True
                running += x
                if running >= 0:
                    if found:
                        res = max(res, running)
                    else:
                        res = max(res, running-1)
                else:
                    running = 0
                    found=False
            return res
        
        
        chars = list(set(s))
        res = 0
        for i in range(len(chars)):
            for j in range(i+1, len(chars)):
                arr = []
                for c in s:
                    if c == chars[i]:
                        arr.append(1)
                    elif c == chars[j]:
                        arr.append(-1)
                res = max(res, Kadane(arr), Kadane([-x for x in arr]))
                
        return res