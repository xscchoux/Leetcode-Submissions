class Solution(object):
    def numberOfArithmeticSlices(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        # Time complexity: O(n^2)
        # Space complexity: O(n^2)

        n = len(nums)
        hmaps = [collections.defaultdict(int) for _ in range(n)]
        count = 0
        
        # hmaps[j][diff]: number of subsequences which consist of at least 2 elements and the difference between elements is "diff"
        
        for i in range(1, n):
            for j in range(i):
                diff = nums[i] - nums[j]
                count += hmaps[j][diff]
                hmaps[i][diff] += hmaps[j][diff] + 1

        return count