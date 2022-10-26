class Solution:
    def checkSubarraySum(self, nums: List[int], k: int) -> bool:
        curr = 0
        hmap = collections.defaultdict(int)
        hmap[0] = -1
        
        for i in range(len(nums)):
            curr = (curr + nums[i])%k
            if curr in hmap:
                if i - hmap[curr] >= 2:
                    return True
            else:
                hmap[curr] = i
        
        return False