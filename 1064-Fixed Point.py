class Solution(object):
    def fixedPoint(self, arr):
        """
        :type arr: List[int]
        :rtype: int
        """
        left, right = 0, len(arr)-1
        
        while left + 1 < right:
            mid = left + (right-left)//2
            if arr[mid] == mid:
                right = mid
            elif arr[mid] < mid:
                left = mid
            else:
                right = mid
                
        if arr[left] == left:
            return left
        elif arr[right] == right:
            return right
        else:
            return -1