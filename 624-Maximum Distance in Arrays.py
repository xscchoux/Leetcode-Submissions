class Solution(object):
    def maxDistance(self, arrays):
        """
        :type arrays: List[List[int]]
        :rtype: int
        """
        mn, mx = arrays[0][0], arrays[0][-1]
        res = 0
        
        for i in range(1, len(arrays)):
            res = max(res, arrays[i][-1]-mn, mx-arrays[i][0])
            
            mx = max(mx, arrays[i][-1])
            mn = min(mn, arrays[i][0])
            
        return res