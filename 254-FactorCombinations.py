class Solution(object):
    def getFactors(self, n):
        """
        :type n: int
        :rtype: List[List[int]]
        """
        if n<4:
            return []
        
        res = []
        self.k = n
        def dfs(n,val, start):
            if val:
                res.append(val+[n])
            for i in range(start,int(n**0.5)+1):   # the upper bound is int(n**0.5), so n//i >=i
                # if n//i < i:
                #     break
                if n%i == 0:
                    dfs(n//i, val+[i], i)
                    
        dfs(n, [], 2)
        return res