class Solution(object):
    def longestMountain(self, arr):
        """
        :type arr: List[int]
        :rtype: int
        """
        N = len(arr)
        
        start = 0
        res = 0
        
        while start < N:
            end = start
            if end + 1 < N and arr[end] < arr[end+1]:
                while end + 1 < N and arr[end] < arr[end+1]:
                    end += 1
                    
                if end + 1 < N and arr[end] > arr[end+1]:
                    while end + 1 < N and arr[end] > arr[end+1]:
                        end += 1
                    
                    res = max(res, end-start+1)
            start = max(start+1, end)
            
        return res