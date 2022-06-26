class Solution(object):
    def maximumsSplicedArray(self, nums1, nums2):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :rtype: int
        """
        sum1 = sum2 = 0
        local1 = local2 = 0
        global1 = global2 = 0
        
        for i in range(len(nums1)):
            sum1 += nums1[i]
            sum2 += nums2[i]
            diff = nums1[i] - nums2[i]
            local1 = max(local1 - diff, 0)
            local2 = max(local2 + diff, 0)
            
            global1 = max(global1, local1)
            global2 = max(global2, local2)
            
        return max(sum1+global1, sum2+global2)