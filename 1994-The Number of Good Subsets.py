class Solution(object):
    def numberOfGoodSubsets(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
# Method 1, O(30* 2^10), 10:number of primes within 30
#         kMod = 1000000007
#         primes = [2, 3, 5, 7, 11, 13, 17, 19, 23, 29]
#         N = len(primes)
#         count = collections.Counter(nums)
#         ans = 0
        
#         def encoding(number):
#             res = 0
#             for i in range(len(primes)):
#                 if number%primes[i] == 0:
#                     res += (1<<i)
#                     number//=primes[i]
#                 if number%primes[i] == 0:
#                     return -1
#             return res

        
#         dp = [0]*(1<<N)
#         dp[0] = 1
        
#         for num, val in count.items():
#             if num == 1:
#                 continue
#             encoded = encoding(num)
#             if encoded == -1: continue
#             for state in range(1, 1<<N):
#                 if state-encoded == state^encoded:
#                     dp[state] += dp[state-encoded]*val
#                     dp[state]%=kMod
                    
#         for i in range(1, 1<<N):
#             if dp[i] != 0:
#                 ans += dp[i]*2**count[1]
#                 ans %= kMod
                
#         return ans
                

    
# Method 2, O(n*2^n), n:numbers
        kMod = 1000000007
        primes = [2,3,5,7,11,13,17,19,23,29]
        count = collections.Counter(nums)
        keys = list(count.keys())
        N = len(count)
        memo = dict()
        
        
        def dfs(ind, mask):
            if ind == N:
                return 1
            
            num = keys[ind]
            ans = dfs(ind+1, mask)
            
            if num != 1 and num%4 != 0 and num%9 != 0 and num != 25:
                currMask = sum([1<<i for i in range(len(primes)) if num%primes[i] == 0])
                if currMask&mask == 0:
                    ans += dfs(ind+1, mask|currMask)*count[num]
            return ans%kMod
        
        return (dfs(0, 0)-1)*2**(count[1])%kMod