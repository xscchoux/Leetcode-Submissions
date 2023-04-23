class Solution:
    def numberOfArrays(self, s: str, k: int) -> int:        
# O(m*logk, the base of log is 10)

        kMod = 1000000007
        @cache
        def dfs(idx):
            if idx == len(s):
                return 1
            if s[idx] == "0":
                return 0
            
            res = num = 0
            for end in range(idx, len(s)):
                num = num*10 + int(s[end])
                if num <= k:
                    res = (res + dfs(end+1))%kMod
                else:
                    break
            return res
        
        return dfs(0)