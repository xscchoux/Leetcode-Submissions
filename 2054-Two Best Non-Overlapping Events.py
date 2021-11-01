class Solution(object):
    def maxTwoEvents(self, events):
        """
        :type events: List[List[int]]
        :rtype: int
        """
        events.sort(key = lambda x: x[1])
        prevMax = []
        res = 0
        maxVal = 0
        
        def bs(arr, st):
            if not arr:
                return -1
            left, right = 0, len(arr)-1
            while left + 1 < right:
                mid = left + (right-left)//2
                if arr[mid][0] < st:
                    left = mid
                else:
                    right = mid
            if arr[right][0] < st:
                return right
            elif arr[left][0] < st:
                return left
            else:
                return -1
        
        for start, end, value in sorted(events, key = lambda x: x[1]):
            index = bs(prevMax, start)
            maxVal = max(value, maxVal)
            res = max(res, maxVal)
            if index >= 0:
                res = max(prevMax[index][1] + value, res)
            prevMax.append([end, maxVal])
            
        return res