class Solution(object):
    def deleteAndEarn(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        hmap = collections.Counter(nums)
        prev = None
        skip = has = 0
        
        for num in sorted(hmap.keys()):
            if num-1 != prev:
                skip, has = max(skip, has), max(skip, has) + num*hmap[num]
            else:
                skip, has = max(skip, has), skip + num*hmap[num]
            prev = num
            
        return max(skip, has)