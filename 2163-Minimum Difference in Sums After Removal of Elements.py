from heapq import *
class Solution(object):
    def minimumDifference(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        # minimize left part and maximize right part
        n = len(nums)//3
        pqLeft, pqRight = [], []
        totLeft = totRight = 0
        leftSum = []
        
        for i in range(0, n):
            totLeft += nums[i]
            totRight += nums[3*n-1-i]
            heappush(pqLeft, -nums[i])
            heappush(pqRight, nums[3*n-1-i])
        leftSum.append(totLeft)
        
        for i in range(n, 2*n):
            if -pqLeft[0] > nums[i]:
                totLeft += nums[i] + heappop(pqLeft)
                heappush(pqLeft, -nums[i])
            leftSum.append(totLeft)

        res = leftSum[-1] - totRight       
        for i in range(2*n-1, n-1, -1):
            if pqRight[0] < nums[i]:
                totRight += nums[i] - heappop(pqRight)
                heappush(pqRight, nums[i])
            res = min(res, leftSum[i-n] - totRight)
                      
        return res