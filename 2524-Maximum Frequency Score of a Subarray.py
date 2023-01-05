class Solution(object):
    def maxFrequencyScore(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
        count = collections.defaultdict(int)
        kMod = 10**9+7
        
        for i in range(k):
            count[nums[i]] += 1
        
        curr = sum(pow(key ,val, kMod) for key, val in count.items())%kMod
        res = curr

        for i in range(k, len(nums)):
            curr = (curr + pow(nums[i], count[nums[i]]+1, kMod) - (pow(nums[i], count[nums[i]], kMod) if count[nums[i]] != 0 else 0))%kMod
            count[nums[i]] += 1
            curr = (curr - pow(nums[i-k], count[nums[i-k]], kMod) + (pow(nums[i-k], count[nums[i-k]]-1, kMod) if count[nums[i-k]] > 1 else 0))%kMod
            count[nums[i-k]] -= 1   
            res = max(curr, res)

        return res