def getPrimes(n):
    """
    Generate all prime numbers less than n using the Sieve of Eratosthenes algorithm
    """
    sieve = [True] * n
    sieve[0] = False
    sieve[1] = False
    for i in range(2, int(n**0.5) + 1):
        if sieve[i]:
            for j in range(i**2, n, i):
                sieve[j] = False
    return [i for i in range(n) if sieve[i]]

primes = getPrimes(1000000)

class Solution:
    def findValidSplit(self, nums: List[int]) -> int:
        hmap = defaultdict(lambda : [0, 0])  # startIdx of a prime: endIdx of a prime
        diff = [0]*(len(nums)+1)
        
        for i, num in enumerate(nums):
            sqrtX = isqrt(num)
            for prime in primes:
                if prime > sqrtX:
                    break
                if num%prime == 0:
                    if prime not in hmap:
                        hmap[prime][0] = i
                    hmap[prime][1] = i
                    while num%prime == 0:
                        num = num//prime
            if num > 1:
                if num not in hmap:
                    hmap[num][0] = i
                hmap[num][1] = i

        for start, end in hmap.values():
            diff[start] += 1
            diff[end] -= 1

        tot = 0
        for i in range(len(nums)-1):
            tot += diff[i]
            if tot == 0:
                return i
        
        return -1