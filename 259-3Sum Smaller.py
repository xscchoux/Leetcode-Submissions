class Solution(object):
    def threeSumSmaller(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: int
        """
        nums.sort()
        ans = 0
        for i in range(len(nums)-2):
            
            j = i + 1
            k = len(nums) - 1
            t = target - nums[i]
            while k > j:
                res = nums[j]+nums[k]
                if res >= t:
                    k-=1
                else:
                    ans += k-j
                    j+=1
        return ans