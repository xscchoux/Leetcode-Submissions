class Solution:
    def primeSubOperation(self, nums: List[int]) -> bool:
        def sieve_of_eratosthenes(n):
            prime = [True for i in range(n+1)]
            p = 2
            while p**2 <= n:
                if prime[p] == True:
                    for i in range(p**2, n+1, p):
                        prime[i] = False
                p += 1
            primes = [p for p in range(2, n+1) if prime[p]]
            return primes

        primes = sieve_of_eratosthenes(1000)
        
        prev = nums[-1]
        
        for i in range(len(nums)-2, -1, -1):
            if nums[i] >= prev:
                found = False
                for prime in primes:
                    if nums[i] - prime < prev and nums[i] - prime >= 1:
                        found = True
                        nums[i] -= prime
                        break
                if not found:
                    return False
            prev = nums[i]
            
        return True