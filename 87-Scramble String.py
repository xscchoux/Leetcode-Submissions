class Solution:
    def isScramble(self, s1: str, s2: str) -> bool:
        
# TLE
#         l1, l2 = list(s1), list(s2)
        
#         def dfs(l1, l2):
#             if sorted(l1) != sorted(l2):
#                 return False
#             if all(l1[i] == l2[i] for i in range(len(l1))):
#                 return True
            
#             for i in range(1, len(l1)):
#                 if dfs(l1[:i], l2[:i]) and dfs(l1[i:], l2[i:]):
#                     return True
#                 if dfs(l1[:i], l2[len(l1)-i:]) and dfs(l1[i:], l2[:len(l1)-i]):
#                     return True
#             return False
        
#         return dfs(l1, l2)

# much better
        memo = dict()
        def dfs(l1, l2):
            key = (l1, l2) if l1 < l2 else (l2, l1)
            if key in memo:
                return memo[key]
            
            if sorted(l1) != sorted(l2):
                memo[key] = False
                return False
            
            if len(l1) == 1:
                return True
            
            for i in range(1, len(l1)):
                if (dfs(l1[:i], l2[:i]) and dfs(l1[i:], l2[i:])) or (dfs(l1[:i], l2[len(l1)-i:]) and dfs(l1[i:], l2[:len(l1)-i])):
                    memo[key] = True
                    return True
            memo[key] = False
            return False
        
        return dfs(s1, s2)
    
# Use cache "key"
        @cache
        def f(s1, s2):
            key = (s1, s2) if s1 < s2 else (s2, s1)
            if sorted(s1) != sorted(s2):
                return False
            
            if len(s1) == 1:
                return True
            
            for i in range(1, len(s1)):
                if f(s1[:i], s2[:i]) and f(s1[i:], s2[i:]) or f(s1[:i], s2[-i:]) and f(s1[i:], s2[:-i]):
                    return True

        return f(s1, s2)