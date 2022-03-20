class Solution(object):
    def minDominoRotations(self, tops, bottoms):
        """
        :type tops: List[int]
        :type bottoms: List[int]
        :rtype: int
        """       
        def check(x):
            rotation1 = rotation2 = 0 
            for i in range(len(tops)):
                if tops[i] != x and bottoms[i] != x:
                    return -1
                elif tops[i] != x:
                    rotation1 += 1
                elif bottoms[i] != x:
                    rotation2 += 1
                    
            return min(rotation1, rotation2)
            
        res = check(tops[0])
        
        if tops[0] == bottoms[0] or res != -1:
            return res
        
        return check(bottoms[0])