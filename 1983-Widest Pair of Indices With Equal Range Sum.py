class Solution(object):
    def widestPairOfIndices(self, nums1, nums2):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :rtype: int
        """
        prefixAll = [0]
        for i in range(len(nums1)):
            prefixAll.append(nums1[i] - nums2[i] + prefixAll[-1])
        
        res = 0
        hmap = dict()
        for i in range(len(prefixAll)):
            if prefixAll[i] not in hmap:
                hmap[prefixAll[i]] = i
            else:
                res = max(res, i-hmap[prefixAll[i]])
        
        return res