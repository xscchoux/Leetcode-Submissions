class Solution(object):
    def minTaps(self, n, ranges):
        """
        :type n: int
        :type ranges: List[int]
        :rtype: int
        """
# O(nlogn)
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


# O(n*m)
        dp = [float('inf')]*(n+1)
        dp[0] = 0
        
        for i in range(n+1):
            left = max(0, i-ranges[i])
            right = min(n, i+ranges[i])
            for j in range(left, right+1):
                dp[right] = min(dp[right], dp[j] + 1)
        
        if dp[n] == float('inf'):
            return -1
        
        return dp[n]


# O(n)
        maxReach = defaultdict(int)
        for i in range(n+1):
            left = max(0, i-ranges[i])
            right = min(n, i+ranges[i])
            maxReach[left] = max(maxReach[left], right)
        
        currReach = 0
        nxtReach = 0
        tap = 0
        
        for i in range(n+1):
            if i > nxtReach:
                return -1
            
            if i > currReach:
                tap += 1
                currReach = nxtReach
            
            nxtReach = max(nxtReach, maxReach[i])
        
        return tap