class Solution(object):
    def minOperations(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
    # sorting + binary search
        
        N = len(nums)
        arr = list(set(nums))
        arr.sort()
        res = N
        
        for i in range(len(arr)):
            j = bisect_right(arr, arr[i] + N - 1)
            count = j - i
            res = min(res, N-count)
        
        return res
    
    # sorting + sliding window
    
        N = len(nums)
        arr = list(set(nums))
        arr.sort()
        res = N
        
        left = 0
        for i in range(len(arr)):
            if arr[i] - arr[left] >= N:
                left += 1
            res = min(res, N-(i-left+1))
        
        return res