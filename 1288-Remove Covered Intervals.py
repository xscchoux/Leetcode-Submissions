class Solution:
    def removeCoveredIntervals(self, intervals: List[List[int]]) -> int:
        intervals.sort(key = lambda x:(x[0], -x[1]))
        
        ans = 1
        maxX = intervals[0][1]
        
        for start, end in intervals:
            if end > maxX:
                maxX = end
                ans += 1
                
        return ans