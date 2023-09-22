class Solution(object):
    def findMedianSortedArrays(self, nums1, nums2):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :rtype: float
        """
        n1, n2 = len(nums1), len(nums2)
        
        if n1 > n2:
            return self.findMedianSortedArrays(nums2, nums1)
        
        left, right = 0, n1+1
        
        while left + 1 <= right:
            partitionNum1 = (left + right)//2
            partitionNum2 = (n1 + n2 + 1)//2 - partitionNum1
            
            maxLeftNum1 = nums1[partitionNum1-1] if partitionNum1 > 0 else float('-inf')
            minRightNum1 = nums1[partitionNum1] if partitionNum1 < n1 else float('inf')

            maxLeftNum2 = nums2[partitionNum2-1] if partitionNum2 > 0 else float('-inf')
            minRightNum2 = nums2[partitionNum2] if partitionNum2 < n2 else float('inf')
            
            if maxLeftNum1 <= minRightNum2 and maxLeftNum2 <= minRightNum1:
                if (n1+n2)%2 == 0:
                    return (max(maxLeftNum1, maxLeftNum2) + min(minRightNum1, minRightNum2)) /float(2)
                else:
                    return max(maxLeftNum1, maxLeftNum2)
            elif maxLeftNum1 > minRightNum2:
                right = partitionNum1
            else:
                left = partitionNum1



class Solution:
    def findMedianSortedArrays(self, nums1: List[int], nums2: List[int]) -> float:
# Recursive binary search
# https://github.com/wisdompeak/LeetCode/blob/master/Priority_Queue/004.Median-of-Two-Sorted-Arrays/4-Median-of-Two-Sorted-Arrays.cpp
        N1, N2 = len(nums1), len(nums2)
        
        def findKth(start1, nums1, start2, nums2, k):
            l1, l2 = len(nums1)-start1, len(nums2)-start2

            if l1 > l2:
                return findKth(start2, nums2, start1, nums1, k)
            
            if start1 == len(nums1):
                return nums2[start2+k-1]
            
            if k == 1:
                return min(nums1[start1], nums2[start2])
            
            k1 = min(k//2, l1)
            k2 = k - k1

            if nums1[start1+k1-1] < nums2[start2+k2-1]:
                return findKth(start1+k1, nums1, start2, nums2, k-k1)
            return findKth(start1, nums1, start2+k2, nums2, k-k2)
        
        if (N1+N2)%2 == 0:
            return (findKth(0, nums1, 0, nums2, (N1+N2)//2) + findKth(0, nums1, 0, nums2, (N1+N2)//2+1 ))/2
        return findKth(0, nums1, 0, nums2, (N1+N2+1)//2 )