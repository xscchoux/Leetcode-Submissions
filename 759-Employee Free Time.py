"""
# Definition for an Interval.
class Interval(object):
    def __init__(self, start=None, end=None):
        self.start = start
        self.end = end
"""

class Solution(object):
    def employeeFreeTime(self, schedule):
        """
        :type schedule: [[Interval]]
        :rtype: [Interval]
        """
        arr = []
        for i in range(len(schedule)):
            for j in range(len(schedule[i])):
                arr.append(schedule[i][j])
                
        arr.sort(key = lambda x:x.start)
        
        # merge intervals
        merged = []
        for i in range(len(arr)):
            if not merged or merged[-1].end < arr[i].start:
                merged.append(arr[i])
            else:
                merged[-1].end = max(merged[-1].end, arr[i].end)
        
        res = []
        for i in range(1, len(merged)):
            res.append(Interval(merged[i-1].end, merged[i].start))
            
        return res