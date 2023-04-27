class Solution:
    def findMaximalUncoveredRanges(self, n: int, ranges: List[List[int]]) -> List[List[int]]:
        currMax = 0
        ranges.sort(key = lambda x:x[0])
        res = []
        
        for u, v in ranges:
            if u > currMax:
                res.append([currMax, u-1])
            currMax = max(v+1, currMax)
        
        if n-1 >= currMax:
            res.append([currMax, n-1])
        
        return res