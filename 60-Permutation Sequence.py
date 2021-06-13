class Solution(object):
    def getPermutation(self, n, k):
        """
        :type n: int
        :type k: int
        :rtype: str
        """           
        
        def factorialFunc(num):
            res = 1
            for i in range(num,0,-1):
                res = res*i
            return res
        
        factorial = factorialFunc(n)
        
        arr = [str(i) for i in range(1, n+1)]
        k-=1
        res = []
        
        while k > 0:
            factorial //= n
            count, k = divmod(k, factorial)
            for i in range(len(arr)):
                if not arr[i]:
                    continue
                if count == 0:
                    res.append(arr[i])
                    arr[i] = None
                    break
                count -= 1
            n-=1
            
        for xx in arr:
            if xx:
                res.append(xx)
        
        return "".join(res)