from math import comb
class Solution:
    def numOfWays(self, nums: List[int]) -> int:
        kMod = 10**9+7
        def dfs(arr):
            N = len(arr)
            if N <= 1:
                return 1
            left = [num for num in arr if num < arr[0]]
            right = [num for num in arr if num > arr[0]]
            
            return ((comb(N-1, len(left))%kMod)*(dfs(left)%kMod)*(dfs(right)%kMod))%kMod
    
        
        return dfs(nums)-1