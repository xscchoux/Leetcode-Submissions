class Solution(object):
    def minimumTotal(self, triangle):
        """
        :type triangle: List[List[int]]
        :rtype: int
        """
# DFS + memoization
        memo = dict()
        row = len(triangle)
        
        def dfs(r, c):
            if r == row:
                return 0
            
            if (r,c) in memo:
                return memo[(r,c)]
            
            left = dfs(r+1, c)
            right = dfs(r+1, c+1)
            memo[(r,c)] = min(left, right) + triangle[r][c]
            return memo[(r,c)]
        
        return dfs(0,0)
    
# DP (bottom-up)
        row = len(triangle)
        for r in range(row-2, -1, -1):
            for c in range(r+1):
                triangle[r][c] += min(triangle[r+1][c], triangle[r+1][c+1])
    
        return triangle[0][0]
        