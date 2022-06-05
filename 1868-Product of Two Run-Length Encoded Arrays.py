class Solution(object):
    def findRLEArray(self, encoded1, encoded2):
        """
        :type encoded1: List[List[int]]
        :type encoded2: List[List[int]]
        :rtype: List[List[int]]
        """
        res = []
        idx1 = idx2 = 0   
        count = 0
        
        while idx1 < len(encoded1) and idx2 < len(encoded2):
            v1, f1 = encoded1[idx1]
            v2, f2 = encoded2[idx2]
            
            freq = min(f1, f2)
            val = v1*v2
            
            encoded1[idx1][1] -= freq
            encoded2[idx2][1] -= freq
            
            if encoded1[idx1][1] == 0:
                idx1 += 1
            if encoded2[idx2][1] == 0:
                idx2 += 1
                
            if not res or val != res[-1][0]:
                res.append([val, freq])
            else:
                res[-1][1] += freq
        
        return res