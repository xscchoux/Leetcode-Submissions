class Solution(object):
    def findClosestElements(self, arr, k, x):
        """
        :type arr: List[int]
        :type k: int
        :type x: int
        :rtype: List[int]
        """
# O(logN + k)
        def bisectLeft(arr, x):
            if not arr:
                return 0
            left, right = 0, len(arr)
            while left + 1 < right:
                mid = left + (right-left)//2
                if arr[mid] >= x:
                    right = mid
                else:
                    left = mid
            if arr[left] >= x:
                return left
            else:
                return right
            
        left = bisectLeft(arr,x)-1
        right = left + 1
        # sliding window which doesn't include arr[left] and arr[right]
        while right- left - 1 < k:
            if right == len(arr):
                left -= 1
            elif left == -1:
                right += 1
            elif abs(arr[left] - x) <= abs(arr[right] - x):
                left -= 1
            else:
                right += 1
                
        return arr[left+1:right]

# Beautiful binary search solution O(log(N-k) + k)    
        if len(arr) == 1 or len(arr) == k:
            return arr
        
        left, right = 0, len(arr)-k
        while left + 1 < right:
            mid = left + (right-left)//2
            if x - arr[mid] > arr[mid+k] - x:
                left = mid
            else:
                right = mid 
        
        if x - arr[left] > arr[left+k] - x:
            return arr[right:right+k]
        
        return arr[left:left+k]