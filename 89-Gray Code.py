class Solution(object):
    def grayCode(self, n):
        """
        :type n: int
        :rtype: List[int]
        """
# backtracking
        visited = set()
        visited.add(0)
        res = [0]
        
        def backtrack(curr):
            if len(visited) == 2**n:
                return True
            for i in range(n):
                nxt = curr^(1<<i)
                if nxt not in visited:
                    visited.add(nxt)
                    res.append(nxt)
                    if backtrack(nxt):
                        return True
                    res.pop()
                    visited.remove(nxt)
            return False
        
        backtrack(0)
        return res

# Recursive
        res = []

        def dfs(n):
            if n == 0:
                res.append(0)
                return
            dfs(n-1)
            resLen = len(res)
            for i in range(resLen-1, -1, -1):
                res.append(res[i]|(1<<(n-1)))
    
        dfs(n)
        return res
    
# iterative
        res = [0]
        for i in range(1, n+1):
            resSize = 1<<(i-1)
            for j in range(resSize-1, -1, -1):
                res.append(res[j]| (1<<(i-1)) )
        
        return res