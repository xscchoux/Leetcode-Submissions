class Solution:
    def getLengthOfOptimalCompression(self, s: str, k: int) -> int:
        
        @cache
        def dfs(ind, prev_char, char_count, k):
            if k < 0:
                return float('inf')
            if ind == len(s):
                return 0
            
            remove_char = dfs(ind+1, prev_char, char_count, k-1)
            
            if s[ind] == prev_char:
                keep_char = dfs(ind+1, prev_char, char_count+1, k) + (char_count in (1, 9, 99))
            else:
                keep_char = 1 + dfs(ind+1, s[ind], 1, k)
                
            return min(remove_char, keep_char)
        
        return dfs(0, "", 0, k)