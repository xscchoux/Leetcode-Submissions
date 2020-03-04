class Solution(object):
    def insert(self, intervals, newInterval):
        """
        :type intervals: List[List[int]]
        :type newInterval: List[int]
        :rtype: List[List[int]]
        """
        if not intervals:
            return [newInterval]

        left, right = 0, len(intervals)-1
        while left<=len(intervals)-1 and intervals[left][1] < newInterval[0]:
            left+=1

        while right>=0 and intervals[right][0] > newInterval[1]:
            right-=1

        # There's overlapping among intervals and newInterval when left - 1 = right
        if left - 1 != right:
            newInterval[0] = min(newInterval[0], intervals[left][0])
            newInterval[1] = max(newInterval[1], intervals[right][1])

        return intervals[:left] + [newInterval] + intervals[right+1:]

intervals = [[1,2],[3,5],[6,7],[8,10],[12,16]]
newInterval = [4,8]
s = Solution()
print(s.insert(intervals, newInterval))