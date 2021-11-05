class Solution(object):
    def sumSubarrayMins(self, arr):
        """
        :type arr: List[int]
        :rtype: int
        """
        kMod = 1000000007
        stack = []
        arr = [float('-inf')] + arr + [float('-inf')]
        res = 0
        
        for ind, num in enumerate(arr):
            while stack and num < arr[stack[-1]]:
                prevBigger = stack.pop()
                res += arr[prevBigger]*(ind-prevBigger)*(prevBigger-stack[-1])
                res%=kMod
            stack.append(ind)
            
        return res