class Solution(object):
    def permuteUnique(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        
# third visit

        res = []
        nums.sort()
        length = len(nums)
        boolean = [False]*length
        def dfs(val, n):
            if n == length:
                res.append(val)
            for i in range(length):
                if i>0 and nums[i] == nums[i-1] and boolean[i-1] == False:  # boolean[i-1] == False means that the (i-1)th item has gone through recursion
                    continue
                if boolean[i] is False:
                    boolean[i] = True
                    dfs(val+[nums[i]], n+1)
                    boolean[i] = False
        dfs([],0)
        return res