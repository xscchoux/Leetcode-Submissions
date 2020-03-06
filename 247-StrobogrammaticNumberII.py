class Solution(object):
    def findStrobogrammatic(self, n):
        """
        :type n: int
        :rtype: List[str]
        """
        
# T(n) = 5 T(n-2) + c
# O(n) = O(5^(n//2))
        
        def dfs(length):
            if length == 0:
                return [""]
            if length == 1:
                return ['1','8','0']
            prev = dfs(length-2)
            res = []
            for a in prev:
                if length < n:
                    res.append('0'+a+'0')
                res.append('8'+a+'8')
                res.append('1'+a+'1')
                res.append('9'+a+'6')
                res.append('6'+a+'9')
            return res
        return dfs(n)