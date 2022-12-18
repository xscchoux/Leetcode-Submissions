class Solution:
    def splitString(self, s: str) -> bool:
        
        def dfs(left, prev):
            if left == len(s):
                return True
            for i in range(left, len(s)):
                curr = int(s[left:i+1])
                if curr > prev:
                    break
                elif curr == prev - 1 and dfs(i+1, curr):
                    return True
            return False
        
        for i in range(len(s)-1):
            num = int(s[:i+1])
            if dfs(i+1, num):
                return True
        
        return False