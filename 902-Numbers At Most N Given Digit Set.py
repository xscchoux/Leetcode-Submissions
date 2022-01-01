class Solution(object):
    def atMostNGivenDigitSet(self, digits, n):
        """
        :type digits: List[str]
        :type n: int
        :rtype: int
        """
        res = 0
        
        strN = str(n)
        N = len(strN)
        
        for i in range(1, N):
            res += pow(len(digits), i)
            
        for i in range(N):
            prefixMatch = False
            for d in digits:
                if int(d) < int(strN[i]):
                    res += pow(len(digits), N-i-1)
                elif int(d) == int(strN[i]):
                    prefixMatch = True
                    break
            if not prefixMatch:
                return res
                    
        return res+1