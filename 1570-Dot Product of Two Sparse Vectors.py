class SparseVector:
    def __init__(self, nums):
        """
        :type nums: List[int]
        """
        self.pairs = []
        for i in range(len(nums)):
            if nums[i] != 0:
                self.pairs.append([i, nums[i]])

    # Return the dotProduct of two sparse vectors
    def dotProduct(self, vec):
        """
        :type vec: 'SparseVector'
        :rtype: int
        """
        i = j = 0
        res = 0
        while i < len(self.pairs) and j < len(vec.pairs):
            if self.pairs[i][0] ==  vec.pairs[j][0]:
                res += self.pairs[i][1]*vec.pairs[j][1]
                i += 1
                j += 1
            elif self.pairs[i][0] < vec.pairs[j][0]:
                i += 1
            else:
                j += 1
        return res

# Your SparseVector object will be instantiated and called as such:
# v1 = SparseVector(nums1)
# v2 = SparseVector(nums2)
# ans = v1.dotProduct(v2)