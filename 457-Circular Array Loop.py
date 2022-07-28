class Solution(object):
    def circularArrayLoop(self, nums):
        """
        :type nums: List[int]
        :rtype: bool
        """
        N = len(nums)
        
        for i in range(N):
            if isinstance(nums[i], str):
                continue
            if nums[i]%N == 0:
                continue
            
            direction = nums[i] > 0
            mark = str(i)
            while not isinstance(nums[i], str) and not direction^(nums[i]>0) and nums[i]%N != 0:
                nxt = (i + nums[i])%N
                nums[i] = mark
                i = nxt
            
            if nums[i] == mark:
                return True
            
        return False