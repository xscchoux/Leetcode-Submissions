class Solution(object):
    def kthFactor(self, n, k):
        """
        :type n: int
        :type k: int
        :rtype: int
        """
        sqrtN = int(n**0.5)
        divisors = []
        for i in range(1, sqrtN+1):
            if n%i == 0:
                divisors.append(i)
                k -= 1
                if k == 0:
                    return i
        
        if sqrtN*sqrtN == n:
            k += 1
        
        return n//divisors[len(divisors)-k] if k <= len(divisors) else -1