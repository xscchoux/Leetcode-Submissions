class Solution(object):
    def minDistance(self, houses, k):
        """
        :type houses: List[int]
        :type k: int
        :rtype: int
        """
        N = len(houses)
        
        if k >= N:
            return 0
        
        memo = dict()
        houses.sort()
        
        def dfs(start, end, boxes):
            # When there's too many boxes and few houses...note that k <= N 
            if boxes > end-start+1:
                return float('inf')
            
            if (start, end, boxes) in memo:
                return memo[(start, end, boxes)]
            
            if boxes == 1:
                median = (start + end)//2
                memo[(start, end, 1)] = sum([ abs( houses[idx] - houses[median] ) for idx in range(start, end+1)])
                return memo[(start, end, 1)]
            
            res = float('inf')
            for x in range(start, end+1):
                res = min(res, dfs(start, x, 1) + dfs(x+1, end, boxes-1)) 
                
            memo[(start, end, boxes)] = res
            return res
        
        return dfs(0, N-1, k)