class Solution(object):
    def longestWPI(self, hours):
        """
        :type hours: List[int]
        :rtype: int
        """
        curr = 0
        res = 0
        
        for i in range(len(hours)):
            if hours[i] > 8:
                curr += 1
            else:
                curr -=1
            
            if curr > 0:
                res = max(res, i+1)
            elif curr-1 in hmap:
                res = max(res, i-hmap[curr-1])
            
            if curr not in hmap:
                hmap[curr] = i
                
        return res