class Solution(object):
    def minimizeTheDifference(self, mat, target):
        """
        :type mat: List[List[int]]
        :type target: int
        :rtype: int
        """
# using set
        R, C = len(mat), len(mat[0])
        
        S = set(mat[0])
        for r in range(1, R):
            NS = set()
            for x in set(mat[r]):
                for y in S:
                    NS.add(x + y)
            S = NS
        
        return min(abs(x - target) for x in S)
    
        
# top-down DP
        row = len(mat)
        col = len(mat[0])
        memo = collections.defaultdict()

        for i in range(len(mat)):
            mat[i].sort()
  
        def dp(i, remain):
            if i == row:
                return abs(remain)
            if (i, remain) in memo:
                return memo[(i, remain)]

            ans = float('inf')
            
            for j in range(col):
                if j > 0 and mat[i][j] == mat[i][j-1]:
                    continue
                ans = min(ans, dp(i+1, remain - mat[i][j]))
                
                if ans == 0:
                    return 0
                
                if remain- mat[i][j] < 0:
                    break
                    
            memo[(i, remain)] = ans
            return ans
        
        res = dp(0, target)
        return res