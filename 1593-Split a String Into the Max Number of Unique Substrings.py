class Solution(object):
    def maxUniqueSplit(self, s):
        """
        :type s: str
        :rtype: int
        """
        visited = set()
        self.res = 0
        def dfs(remain):
            if not remain:
                self.res = max(self.res, len(visited))
                return
            for i in range(1,len(remain)+1):
                w = remain[:i]
                if w not in visited:
                    visited.add(w)
                    dfs(remain[i:])
                    visited.remove(w)
        
        dfs(s)
        
        return self.res