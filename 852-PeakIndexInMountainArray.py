class Solution(object):
    def peakIndexInMountainArray(self, A):
        """
        :type A: List[int]
        :rtype: int
        """
        left, right = 1, len(A)-2
        
        while left+1<right:
            mid = left + (right-left)//2
            if A[mid]<A[mid+1]:
                left = mid
            else:
                right = mid
                
        if A[left]>A[left+1]:
            return left
        else:
            return right