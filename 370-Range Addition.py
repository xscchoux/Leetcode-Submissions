class Solution(object):
    def getModifiedArray(self, length, updates):
        """
        :type length: int
        :type updates: List[List[int]]
        :rtype: List[int]
        """
# naive approach (TLE)
#         res = [0]*length
#         for update in updates:
#             start, end, val = update[0], update[1], update[2]
#             for i in range(start, end+1):
#                 res[i] += val
        
#         return res
    
# Range caching, O(k+N)
        res = [0]*length
        for update in updates:
            start, end, val = update[0], update[1], update[2]
            res[start] += val
            if end + 1 < length:
                res[end+1] -= val
        
        for i in range(1, length):
            res[i] += res[i-1]
            
        return res