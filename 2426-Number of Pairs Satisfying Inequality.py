from sortedcontainers import SortedList
class Solution(object):
    def numberOfPairs(self, nums1, nums2, diff):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :type diff: int
        :rtype: int
        """
        # nums1[i] - nums2[i] <= nums1[j] - nums2[j] + diff
        
        sl = SortedList()
        res = 0
        for i in range(len(nums1)):
            curr = nums1[i] - nums2[i] + diff
            idx = sl.bisect_right(curr)
            res += idx
            sl.add(nums1[i]-nums2[i])
        return res