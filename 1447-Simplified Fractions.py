class Solution(object):
    def simplifiedFractions(self, n):
        """
        :type n: int
        :rtype: List[str]
        """
        if n<=1:
            return []
        
        res = []
        visited = set()
        
        for i in range(2,n+1):
            for j in range(1,i):
                if j/float(i) not in visited:
                    visited.add(j/float(i))
                    res.append(str(j)+'/'+str(i))

        return res