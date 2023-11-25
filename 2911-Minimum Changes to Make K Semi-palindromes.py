# O(n^3*log(n))
class Solution:
    def minimumChanges(self, s: str, k: int) -> int:
        # dp[i][j] = min( v[i][x] + dp[x+1][j] )
        # dp[i][j] is the minimum number of letter changes to change suffix s[i:] into j valid semi-palidromes
        # v[i][x] is the minimum number of letter changes to change substring s[i..x] into semi-palindrome
        # note that there are at least two characters in a semi-palindrome
        
        N = len(s)
        
        @cache
        def dp(start, k):
            if k == 1:
                return v(start, N-1)
            
            res = float('inf')
            for end in range(start+1, N-2):
                res = min(res, v(start, end) + dp(end+1, k-1))
            return res
            
        @cache
        def v(start, end):
            minCount = float('inf')
            length = end-start+1
            
            for d in range(1, length):
                if length%d != 0:
                    continue
                count = 0
                substrings = length//d
                
                for offset in range(d):
                    for i in range(substrings//2):
                        if s[start + offset + i*d] != s[start + offset + (substrings-1-i)*d]:
                            count += 1
                
                minCount = min(minCount, count)
            
            return minCount
        
        return dp(0, k)