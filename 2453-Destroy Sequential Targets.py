class Solution(object):
    def destroyTargets(self, nums, space):
        """
        :type nums: List[int]
        :type space: int
        :rtype: int
        """
        hmap = collections.defaultdict(int) # num:count by far
        nums.sort(reverse=True)
        val = 0
        res = float('inf')
        
        for i, num in enumerate(nums):
            curr = num%space
            if curr in hmap:
                hmap[curr] += 1
            elif (curr+space)%space in hmap:
                hmap[curr] = hmap[(curr+space)%space] + 1
            else:
                hmap[curr] = 1
            if hmap[curr] >= val:
                val = hmap[curr]
                res = nums[i]
                
        return res