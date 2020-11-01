import heapq
class Solution(object):
    def smallestRange(self, nums):
        """
        :type nums: List[List[int]]
        :rtype: List[int]
        """
        rangeMin = float('inf')
        rangeMax = float('-inf')       
        minheap = []
        
        for i in range(len(nums)):
            heapq.heappush(minheap, (nums[i][0], i, 0))
            rangeMin = min(rangeMin, nums[i][0])
            rangeMax = max(rangeMax, nums[i][0])
        
        bestMin, bestMax = rangeMin, rangeMax
        
        res = [bestMin, bestMax]
        
        while True:
            _, row, col = heapq.heappop(minheap)
            if col + 1 < len(nums[row]):
                heapq.heappush(minheap, (nums[row][col+1], row, col+1))
            else:
                break
            rangeMin = minheap[0][0]
            rangeMax = max(rangeMax, nums[row][col+1])
            if rangeMax-rangeMin < bestMax-bestMin:
                bestMin, bestMax = rangeMin, rangeMax
                res = [bestMin, bestMax]
        return res