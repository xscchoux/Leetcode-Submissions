class Solution(object):
    def findRightInterval(self, intervals):
        """
        :type intervals: List[List[int]]
        :rtype: List[int]
        """
# each start_i is "unique"!
# binary search, O(NlogN)

        hmap = {interval[0]:ind for ind, interval in enumerate(intervals)}
        startList = [interval[0] for interval in intervals]
        startList.sort()
        res = []
        
        def bs(startList, endpos):
            left, right = 0, len(startList)-1
            while left + 1 < right:
                mid = left + (right-left)//2
                if startList[mid] >= endpos:
                    right = mid
                else:
                    left = mid
            if startList[left] >= endpos:
                return left
            elif startList[right] >= endpos:
                return right
            else:
                return -1
        
        for interval in intervals:
            pos = bs(startList, interval[1])
            if pos == -1:
                res.append(-1)
            else:
                res.append(hmap[startList[pos]])
        return res
    
# two arrays (sort by start and sort by end)
        N = len(intervals)
        startArr = intervals
        endArr = [interval[:] for interval in intervals]
        hmap = {interval[0]:ind for ind, interval in enumerate(intervals)}
        
        startArr.sort(key = lambda x: x[0])
        endArr.sort(key = lambda x: x[1])
        
        res = [-1]*N
        startIdx = 0
        
        for endIdx in range(len(intervals)):
            while startIdx < N and startArr[startIdx][0] < endArr[endIdx][1]:
                startIdx += 1
            if startIdx < N:
                res[hmap[endArr[endIdx][0]]] = hmap[startArr[startIdx][0]]
            else:
                res[hmap[endArr[endIdx][0]]] = -1
        
        return res