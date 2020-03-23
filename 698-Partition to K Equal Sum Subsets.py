class Solution(object):
    def canPartitionKSubsets(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: bool
        """
        
# https://www.youtube.com/watch?v=O17fztIRR3I
        _sum = sum(nums)
        
        if _sum%k != 0:
            return False
        
        target = _sum//k
        
        nums.sort()
        if nums[-1] > target:
            return False
        
        while nums[-1] == target:
            k-=1
            nums.pop()
        
        subsets = [0]*k
        
        def dfs():
            if not nums:
                return True            
            v = nums.pop()
            for i in range(len(subsets)):
                if subsets[i] + v <= target:
                    subsets[i] += v
                    if dfs():
                        return True
                    subsets[i] -= v
                if not subsets[i]:      # avoid duplicate cases
                    break
            nums.append(v)
        
        return dfs()