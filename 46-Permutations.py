class Solution(object):
    def permute(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
# Time complexity: O(N*N!), space complexity: O(N!)
        res = []
        length = len(nums)
        boolean = [False]*length
        
        def dfs(val, n):
            if n == length:
                res.append(val)
                return
            for i in range(length):
                if boolean[i] is False:
                    boolean[i] = True
                    dfs(val+[nums[i]], n+1)
                    boolean[i] = False
        
        dfs([],0)
        return res