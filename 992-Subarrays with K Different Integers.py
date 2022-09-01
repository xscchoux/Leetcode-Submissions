class Solution(object):
    def subarraysWithKDistinct(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
        window1, window2 = collections.defaultdict(int), collections.defaultdict(int)
        
        left1 = left2 = res = 0
        
        for i, num in enumerate(nums):
            window1[num] += 1
            window2[num] += 1
            
            while len(window1) > k:
                window1[nums[left1]] -= 1
                if window1[nums[left1]] == 0:
                    del window1[nums[left1]]
                left1 += 1
                
            while len(window2) >= k:
                window2[nums[left2]] -= 1
                if window2[nums[left2]] == 0:
                    del window2[nums[left2]]
                left2 += 1
            res += left2-left1
            
        return res