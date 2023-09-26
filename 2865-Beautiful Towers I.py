class Solution:
    def maximumSumOfHeights(self, maxHeights: List[int]) -> int:
        N = len(maxHeights)
        res = 0
        
        for i in range(N):
            tot = maxHeights[i]
            
            currMax = maxHeights[i]
            for j in range(i-1, -1, -1):
                currMax = min(currMax, maxHeights[j])
                tot += currMax

            currMax = maxHeights[i]
            for j in range(i+1, N):
                currMax = min(currMax, maxHeights[j])
                tot += currMax
            
            res = max(res, tot)
        
        return res