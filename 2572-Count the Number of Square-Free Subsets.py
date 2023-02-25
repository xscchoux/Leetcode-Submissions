class Solution:
    def squareFreeSubsets(self, nums: List[int]) -> int:
        
# Top-down, TLE
#         primes = [2,3,5,7,11,13,17,19,23,29]
#         kMod = 1000000007
#         s_not_free = {4, 8, 9, 12, 16, 18, 20, 24, 25, 27, 28}
#         nums = [num for num in nums if num not in s_not_free]
#         if not nums:
#             return 0

#         @cache
#         def dp(ind, mask):
#             if ind == len(nums):
#                 return 1
            
#             flag = True
#             res = dp(ind+1, mask)%kMod
            
#             num = nums[ind]
#             for j in range(10):
#                 if num%primes[j] == 0 and (mask&(1<<j)):
#                     flag = False
#                     break
#                 elif num%primes[j] == 0:
#                     mask = (mask^(1<<j))

#             if flag:
#                 res = (res + dp(ind+1, mask))%kMod

#             return res
        
#         return (dp(0, 0)-1)%kMod   


# bottom up
# https://www.youtube.com/watch?v=neTEvUqLMLk&t=1381s
#         s_not_free = {4, 8, 9, 12, 16, 18, 20, 24, 25, 27, 28}
#         nums = [num for num in nums if num not in s_not_free]
#         if not nums:
#             return 0
#         primes = [2,3,5,7,11,13,17,19,23,29]
#         kMod = 1000000007
#         N = len(nums)
#         dp = [[0]*1025 for i in range(N+1)]
#         dp[0][0] = 1
        
#         @cache
#         def encode(num):
#             state = 0
#             for i in range(10):
#                 count = 0
#                 while num%primes[i] == 0:
#                     num = num//primes[i]
#                     count += 1
#                 if count >= 2:
#                     return -1
#                 if count == 1:
#                     state = state|(1<<i)
#             return state
        
#         res = 0
#         for i in range(1, N+1):
#             bits = encode(nums[i-1])
#             for state in range(0, 1<<10):
#                 if nums[i-1] == 1:
#                     dp[i][state] = (dp[i-1][state]*2)%kMod
#                 else:
#                     dp[i][state] = dp[i-1][state]
#                     if bits != -1 and (state&bits) == bits:
#                         dp[i][state] = (dp[i][state] + dp[i][state-bits])%kMod
#                 if i == N:
#                     res = (res + dp[i][state])%kMod

#         return (res-1)%kMod


# ideal solution
        kMod = 1000000007
        s_not_free = {1, 4, 8, 9, 12, 16, 18, 20, 24, 25, 27, 28}
        ones = nums.count(1)
        nums = [num for num in nums if num not in s_not_free]
        count = Counter(nums)

        def dfs(arr):
            if not arr:
                return 1
            if len(arr) == 1:
                return count[arr[0]] + 1

            res = 0
            tmp = []
            for j in range(1, len(arr)):
                if math.gcd(arr[0], arr[j]) == 1:
                    tmp.append(arr[j])
            res = (res + dfs(arr[1:]) + count[arr[0]]*dfs(tmp)%kMod)%kMod
            return res
        
        return (dfs( list(count.keys()) )*pow(2, ones, kMod) - 1)%kMod