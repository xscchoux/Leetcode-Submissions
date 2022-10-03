class Solution(object):
    def xorAllNums(self, nums1, nums2):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :rtype: int
        """
        remainder1, remainder2 = len(nums1)%2, len(nums2)%2

        # if not remainder1 and not remainder2:
        #     return 0
        # elif remainder1 and not remainder2:
        #     return reduce(lambda x, y: x^y, nums2, 0)
        # elif remainder2 and not remainder1:
        #     return reduce(lambda x, y: x^y, nums1, 0)
        # return reduce(lambda x, y: x^y, nums2, 0)^reduce(lambda x, y: x^y, nums1, 0)
    
# more concise:

        # return (remainder1*reduce(lambda x, y: x^y, nums2, 0))^(remainder2*reduce(lambda x, y: x^y, nums1, 0))

# even more concise:
        return (remainder1*reduce(xor, nums2))^(remainder2*reduce(xor, nums1))