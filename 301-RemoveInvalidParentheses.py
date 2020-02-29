from collections import deque
class Solution(object):
    def removeInvalidParentheses(self, s):
        """
        :type s: str
        :rtype: List[str]
        """
# BFS
        # a: mismatched "(" , b: mismatched ")"
    
        def mismatches(s):
            a = b = 0
            for c in s:
                a += {"(":1, ")":-1}.get(c,0)
                b += a<0
                a = max(a, 0)
            return a+b
        
        visited = set()
        visited.add(s)
        queue = deque([])
        queue.append(s)
        res = []
        
        while queue:
            string = queue.popleft()
            mismatchNum = mismatches(string)
            if mismatchNum == 0:
                res.append(string)
                continue
            for i in range(len(string)):
                if i!=0 and string[i] == string[i-1]:
                    continue
                if string[i] in ("(",")"):
                    newString = string[:i]+string[i+1:]
                    if mismatches(newString) < mismatchNum and newString not in visited:
                        queue.append(newString)
                        visited.add(newString)    
        return res
    
# DFS
        def mismatches(s):
            a = b = 0
            for c in s:
                a += {"(":1, ")":-1}.get(c,0)
                b += a<0
                a = max(a, 0)
            return a+b
        
        def dfs(s):
            mismatchNum = mismatches(s)
            if mismatchNum == 0:
                res.append(s)
                return
            for i in range(len(s)):
                if i!=0 and s[i] == s[i-1]:
                    continue
                if s[i] in ("(",")"):
                    newString = s[:i]+s[i+1:]
                    if newString not in visited and mismatches(newString) < mismatchNum:
                        visited.add(newString)
                        dfs(newString)
        
        visited = set()
        visited.add(s)
        res = []
        dfs(s)
        return res