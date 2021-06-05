class Solution(object):
    def eraseOverlapIntervals(self, intervals):
        """
        :type intervals: List[List[int]]
        :rtype: int
        """
        
        intervals.sort(key = lambda x:x[1])
        count = 0
        
        prev = float('-inf')
        for interval in intervals:
            if interval[0] >= prev:
                prev = interval[1]
            else:
                count += 1
        return count