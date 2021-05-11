class Solution(object):
    def countPrimes(self, n):
        """
        :type n: int
        :rtype: int
        """
        if n <= 2:
            return 0
        
        arr = [0]*2 + [1]*(n-2)
        
        for i in range(2, int(n**0.5)+1):
            if arr[i]:
                arr[i+i:n:i] = [0]*len(arr[i+i:n:i])
        
        return sum(arr)