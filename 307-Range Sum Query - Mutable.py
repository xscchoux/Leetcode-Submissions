# https://www.geeksforgeeks.org/binary-indexed-tree-or-fenwick-tree-2/
# https://www.youtube.com/watch?v=G9GRvQRtGOc
class NumArray(object):

    def __init__(self, nums):
        """
        :type nums: List[int]
        """
        self.n = len(nums)
        self.nums = nums
        self.BITree = [0]*(self.n+1)
        for ind, val in enumerate(nums):
            self.updateBITree(ind+1, val)
    
    
    def updateBITree(self, BITindex, val):
        while BITindex <= self.n:
            self.BITree[BITindex] += val
            BITindex += BITindex&(-BITindex)
    
    def getSum(self, BITindex):
        res = 0
        while BITindex > 0:
            res += self.BITree[BITindex]
            BITindex -= BITindex&(-BITindex)
        return res
    
    def update(self, index, val):
        """
        :type index: int
        :type val: int
        :rtype: None
        """
        diff = val - self.nums[index]
        self.nums[index] = val
        self.updateBITree(index+1, diff)

    def sumRange(self, left, right):
        """
        :type left: int
        :type right: int
        :rtype: int
        """
        return self.getSum(right+1) - self.getSum(left)


# Your NumArray object will be instantiated and called as such:
# obj = NumArray(nums)
# obj.update(index,val)
# param_2 = obj.sumRange(left,right)