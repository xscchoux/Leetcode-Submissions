class NumArray(object):

    def __init__(self, nums):
        """
        :type nums: List[int]
        """
        self.preSum = [0]
        for i in range(len(nums)):
            self.preSum.append(self.preSum[i] + nums[i])

    def sumRange(self, left, right):
        """
        :type left: int
        :type right: int
        :rtype: int
        """
        return self.preSum[right+1] - self.preSum[left]


# Your NumArray object will be instantiated and called as such:
# obj = NumArray(nums)
# param_1 = obj.sumRange(left,right)