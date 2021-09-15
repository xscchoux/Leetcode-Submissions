class Solution(object):
    def maxTurbulenceSize(self, arr):
        """
        :type arr: List[int]
        :rtype: int
        """
# sliding window

        def compare(a, b):
            if a > b: return 1
            elif a == b: return 0
            else: return -1
        
        N = len(arr)
        res = 1
        left = 0
        
        for i in range(1, N):
            if arr[i] == arr[i-1]:
                left += 1
                continue
            if i == N-1 or compare(arr[i], arr[i-1])*compare(arr[i+1],arr[i]) != -1:
                res = max(res, i - left + 1)
                left = i
        
        return res
    
# DP
        larger = smaller = 1
        res = 1
        
        for i in range(1, len(arr)):
            currLarger = currSmaller = 1
            if arr[i] > arr[i-1]:
                currLarger = smaller + 1
            elif arr[i] < arr[i-1]:
                currSmaller = larger + 1
                
            res = max(res, currSmaller, currLarger)
            larger, smaller = currLarger, currSmaller
            
        return res