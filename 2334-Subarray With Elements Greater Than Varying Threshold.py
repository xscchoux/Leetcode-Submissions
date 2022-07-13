class Solution(object):
    def validSubarraySize(self, nums, threshold):
        """
        :type nums: List[int]
        :type threshold: int
        :rtype: int
        """
        # maximal rectangle
        nums.append(-1)
        stack = []
        res = 0
        for i in range(len(nums)):
            while stack and nums[i] < nums[stack[-1]]:
                preInd = stack.pop()
                if not stack:
                    w = i
                else:
                    w = i - stack[-1] - 1
                res = max(res, w*nums[preInd])
                if res > threshold:
                    return w
            stack.append(i)
        return -1