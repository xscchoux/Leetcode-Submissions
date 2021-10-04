class Solution(object):
    def waysToPartition(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
# https://www.youtube.com/watch?v=iEARhupL4Qk&ab_channel=ProgrammingLivewithLarry
        res = 0
        total = sum(nums)
        prefixSum = 0
        diff = []
        for i in range(len(nums)):
            prefixSum += nums[i]
            suffixSum = total-prefixSum
            if prefixSum == suffixSum:
                res += 1
            diff.append( prefixSum - suffixSum)
            
        left = collections.defaultdict(int)
        right = collections.Counter(diff)

        for i in range(len(diff)):
            change = k - nums[i]
            res = max(res, left[change] + right[-change])
            right[diff[i]] -= 1
            left[diff[i]] += 1
            
        res = max(res, left[k-nums[-1]])
            
        return res
            
# ----------------------------
# | prefixSum (changed last) | 
# ----------------------------------------
#                            | suffixSum |
#                            -------------
                
# -----------------------------------------
# |diff(left) (changed last) | diff(right)|
# -----------------------------------------