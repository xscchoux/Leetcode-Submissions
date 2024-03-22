class Solution:
    def maximumSubarraySum(self, nums: List[int], k: int) -> int:
        hmap = defaultdict(lambda:float('inf'))  # num:preSum
        preSum = 0
        res = float('-inf')
        for i in range(len(nums)):
            if nums[i] - k in hmap:
                res = max(res, preSum + nums[i] - hmap[nums[i]-k])
            if nums[i] + k in hmap:
                res = max(res, preSum + nums[i] - hmap[nums[i]+k])
            hmap[nums[i]] = min(hmap[nums[i]], preSum)
            preSum += nums[i]

        return res if res > float('-inf') else 0