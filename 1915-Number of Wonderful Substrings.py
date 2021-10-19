class Solution(object):
    def wonderfulSubstrings(self, word):
        """
        :type word: str
        :rtype: int
        """
        
# TLE
#         prefixBit = collections.defaultdict(int)
#         prefixBit[0] = 1
#         res = 0
#         prev = 0
        
#         for s in word:
#             offset = ord(s)-ord('a')
#             curr = (1<<offset)^prev
            
#             for key in prefixBit.keys():
#                 XOR = curr^key
#                 if XOR - (XOR & -XOR) == 0:
#                     res += prefixBit[key]
            
#             prefixBit[curr] += 1
#             prev = curr
        
#         return res

# beautiful solution

        dp = [1] + [0]*1024
        prev = 0
        res = 0
        
        for s in word:
            curr = (1<<(ord(s)-ord('a')))^prev
            res += dp[curr]
            for i in range(10):
                res+= dp[curr^(1<<i)]
            dp[curr] += 1
            prev = curr
        return res