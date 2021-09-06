class Solution(object):
    def numberOfWeakCharacters(self, properties):
        """
        :type properties: List[List[int]]
        :rtype: int
        """
        properties.sort(key = lambda x: (-x[0], x[1]))
        
        maxDefense = 0
        res = 0
        
        for _, defense in properties:
            if defense < maxDefense:
                res += 1
            if defense > maxDefense:
                maxDefense = defense
                
        return res