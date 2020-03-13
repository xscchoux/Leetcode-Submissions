class Solution(object):
    def canPartition(self, nums):
        """
        :type nums: List[int]
        :rtype: bool
        """
# time complexity: O(2^N)

        _sum = sum(nums)
        if _sum%2 != 0:
            return False
        nums.sort()
        n = len(nums)
        target = _sum//2
        self.boolean = False
        
        def dfs(start, val):
            if self.boolean:
                return
            if val == target:
                self.boolean = True
                return
            for i in range(start, n):
                if i>start and nums[i] == nums[i-1]:
                    continue
                if val + nums[i] > target:
                    break
                dfs(i+1, val+nums[i])
        dfs(0,0)
        return self.boolean