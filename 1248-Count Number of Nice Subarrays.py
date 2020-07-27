class Solution(object):
    def numberOfSubarrays(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
# sliding window
# O(n)
        total = 0
        oddNumber = 0
        res = 0
        left = 0
        for i in range(len(nums)):
            if nums[i]%2 == 1:
                oddNumber += 1
                total = 0
                while k == oddNumber:
                    total += 1
                    if nums[left] %2 == 1:
                        oddNumber -= 1
                    left += 1
            res += total
        return res