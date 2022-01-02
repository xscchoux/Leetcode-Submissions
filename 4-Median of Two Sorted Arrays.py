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