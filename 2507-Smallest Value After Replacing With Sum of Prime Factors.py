class Solution:
    def smallestValue(self, n: int) -> int:
        
        def findPrime(num):
            ans = []
            c = 2
            while num > 1:
                if num%c == 0:
                    ans.append(c)
                    num = num//c
                else:
                    c += 1
            return ans
        
        prev = float('inf')
        
        while True:
            primes = findPrime(n)
            n = sum(primes)
            if n < prev:
                prev = n
            else:
                return prev