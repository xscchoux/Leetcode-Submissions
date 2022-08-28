from sortedcontainers import SortedList
class Solution(object):
    def maximumSegmentSum(self, nums, removeQueries):
        """
        :type nums: List[int]
        :type removeQueries: List[int]
        :rtype: List[int]
        """
# https://www.youtube.com/watch?v=A1-KH4x6aY8&t=470s&ab_channel=ProgrammingLivewithLarry
        segments = SortedList()
        sums = SortedList()
        preSum = [0]
        res = []
        for num in nums:
            preSum.append(preSum[-1] + num)
            
        segments.add((0, len(nums)-1, preSum[-1]))
        sums.add(preSum[-1])
        
        for i in range(len(removeQueries)):
            curr = removeQueries[i]
            segment_idx = segments.bisect_right((curr, float('inf'), float('inf'))) - 1
            left, right, tot = segments[segment_idx]
            
            segments.pop(segment_idx)
            sums.remove(tot)
            
            if left != curr:
                segments.add((left, curr-1, preSum[curr] - preSum[left] ))
                sums.add(preSum[curr] - preSum[left])
            if right != curr:
                segments.add((curr+1, right, preSum[right+1] - preSum[curr+1] ))
                sums.add(preSum[right+1] - preSum[curr+1])
                
            if sums:
                res.append(sums[-1])
            else:
                res.append(0)
        
        return res