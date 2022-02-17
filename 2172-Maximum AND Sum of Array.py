class Solution(object):
    def maximumANDSum(self, nums, numSlots):
        """
        :type nums: List[int]
        :type numSlots: int
        :rtype: int
        """
        N = len(nums)
        memo = dict()
        
        def dfs(ind, state):
            if (ind, state) in memo:
                return memo[(ind, state)]
            if ind == N:
                return 0
            res = 0
            for i in range(numSlots):
                if ((state >> (2*i) ) & 1) != 0:
                    res = max(res, ((i+1) & nums[ind]) + dfs(ind+1, (state^(1<<2*i))^(1<<(2*i+1))))
                elif (state >> (2*i+1)) & 1 == 0  and (state >> (2*i) ) & 1 == 0:
                    res = max(res, ((i+1) & nums[ind]) + dfs(ind+1, state^(1<<2*i)))
            memo[(ind, state)] = res
            return res
        
        return dfs(0, 0)