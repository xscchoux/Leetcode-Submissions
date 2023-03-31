class Solution:
    def ways(self, pizza: List[str], k: int) -> int:
        row, col = len(pizza), len(pizza[0])
        kMod = 1000000007
        
        apples = [[0]*(col+1) for _ in range(row+1)]
        for r in range(row):
            for c in range(col):
                apples[r+1][c+1] = apples[r+1][c] + apples[r][c+1] - apples[r][c] + (pizza[r][c] == "A")
                
        def hasApple(r1, c1, r2, c2):
            if (apples[r2+1][c2+1] - apples[r2+1][c1] - apples[r1][c2+1] + apples[r1][c1]) > 0:
                return 1
            return 0
   
        # ways to cut pizza[startR:row][startC:col] into (remain+1) pieces
        @cache
        def dfs(startR, startC, remain):
            if remain == 0:
                if hasApple(startR, startC, row-1, col-1) > 0:
                    return 1
                return 0
            val = 0
            for r in range(startR, row-1):
                val = (val + hasApple(startR, startC, r, col-1)*dfs(r+1, startC, remain-1))%kMod
            for c in range(startC, col-1):
                val = (val + hasApple(startR, startC, row-1, c)*dfs(startR, c+1, remain-1))%kMod
            
            return val
        
        return dfs(0, 0, k-1)