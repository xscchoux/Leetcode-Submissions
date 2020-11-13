class Solution(object):
    def nextGreaterElement(self, nums1, nums2):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :rtype: List[int]
        """
        stack = []
        hmap = dict()
        for num in nums2:
            while stack and num > stack[-1]:
                hmap[stack.pop()] = num
            stack.append(num)
            
        res = []
        
        for num in nums1:
            if num in hmap:
                res.append(hmap[num])
            else:
                res.append(-1)
        return res