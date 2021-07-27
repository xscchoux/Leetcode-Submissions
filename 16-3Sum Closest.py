class Solution(object):
    def threeSumClosest(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: int
        """
        nums.sort()
        tmp = float('inf')
        res = 0
        
        for i in range(len(nums)-2):
            j = i+1
            k = len(nums)-1
            while j < k:
                summ = nums[i] + nums[j] + nums[k]
                if summ == target:
                    return summ
                diff = summ - target
                if abs(diff) < tmp:
                    res = summ
                    tmp = abs(diff)
                if diff > 0:
                    k -= 1
                else:
                    j += 1
                    
        return res