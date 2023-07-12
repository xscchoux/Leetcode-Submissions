class Solution:
    def maximumSum(self, arr: List[int]) -> int:
        dp0, dp1 = arr[0], float('-inf') # without deletion, with deletion so far 
        res = arr[0]
        
        for i in range(1, len(arr)):
            preDP0, preDP1 = dp0, dp1
            dp0 = max(arr[i], preDP0 + arr[i])
            dp1 = max(preDP1 + arr[i], preDP0)
            res = max(res, dp0, dp1)
            
        return res