class Solution(object):
    def findClosestElements(self, arr, k, x):
        """
        :type arr: List[int]
        :type k: int
        :type x: int
        :rtype: List[int]
        """
        
# solution 1
# O(logN + K)
        index = self.findIndex(arr,x)
        left, right = index, index+1
        res = []
        for i in range(k):
            if right==len(arr):
                res.append(arr[left])
                left-=1
            elif left<0:
                res.append(arr[right])
                right+=1
            else:
                if x - arr[left] > arr[right]- x:
                    res.append(arr[right])
                    right+=1
                else:
                    res.append(arr[left])
                    left-=1
        return sorted(res)
        
    def findIndex(self, arr, x):
        left, right = 0, len(arr)-1
        while left+1<right:
            mid = left + (right-left)//2
            if arr[mid]<=x:
                left = mid
            else:
                right = mid
        
        if arr[right]<=x:
            return right
        else:
            return left
        
# Solution 2
# time complexity: O(logN)
        if len(arr) == 1:
            return arr
        left, right = 0, len(arr)-k
        while left+1<right:
            mid = left + (right-left)//2
            if x-arr[mid] > arr[mid+k]-x:
                left = mid
            else:
                right = mid
        if x-arr[left] > arr[left+k] - x:
            return arr[right:right+k]
        return arr[left:left+k]