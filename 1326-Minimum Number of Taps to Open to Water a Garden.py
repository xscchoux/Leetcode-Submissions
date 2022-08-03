class Solution(object):
    def minTaps(self, n, ranges):
        """
        :type n: int
        :type ranges: List[int]
        :rtype: int
        """
        span = []
        for i in range(len(ranges)):
            span.append([max(0, i-ranges[i]), min(i+ranges[i], n)])
        span.sort(key = lambda x:x[0])
        
        idx = 0
        res = 0
        maxDis = 0
        
        while idx < len(ranges):
            if maxDis == n:
                return res
            
            nxtIdx = idx
            found = False
            nxtMaxDis = maxDis
            
            while nxtIdx < len(span) and span[nxtIdx][0] <= maxDis:
                if span[nxtIdx][1] > maxDis:
                    nxtMaxDis = max(nxtMaxDis, span[nxtIdx][1])
                    found = True
                nxtIdx += 1
            if not found:
                return -1
            res += 1
            idx = nxtIdx
            maxDis = nxtMaxDis

        return res