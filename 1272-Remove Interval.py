class Solution(object):
    def removeInterval(self, intervals, toBeRemoved):
        """
        :type intervals: List[List[int]]
        :type toBeRemoved: List[int]
        :rtype: List[List[int]]
        """
        arr = []
        startRemove, endRemove = toBeRemoved
        
        for start, end in intervals:
            if end <= startRemove or start >= endRemove:
                arr.append([start, end])
                continue
            if start < startRemove:
                arr.append([start, startRemove])
            if end > endRemove:
                arr.append([endRemove, end])
                
        return arr