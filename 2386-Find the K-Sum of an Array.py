from heapq import heappush, heappop
class Solution(object):
    def kSum(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
# https://leetcode.com/problems/find-the-k-sum-of-an-array/discuss/2461580/Python3-Finding-next-bigger-sum-from-an-all-positive-sorted-nums

        maxSum = 0
        for num in nums:
            if num > 0:
                maxSum += num
        
        if k == 1:
            return maxSum
        
        nums = sorted([abs(num) for num in nums])
        pq = [(nums[0], 0)]
        
        for _ in range(k-1):
            curr, index = heappop(pq)
            
            if index + 1 < len(nums):
                heappush(pq, (curr - nums[index] + nums[index+1], index+1))
                heappush(pq, (curr+nums[index+1], index+1))
        
        return maxSum-curr