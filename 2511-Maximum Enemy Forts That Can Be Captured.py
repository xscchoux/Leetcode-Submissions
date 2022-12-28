class Solution:
    def captureForts(self, forts: List[int]) -> int:
        res = 0
        ii = 0
        
        for i, x in enumerate(forts):
            if x:
                if forts[i] == -forts[ii]:
                    res = max(res, i-ii-1)
                ii = i
                
        return res