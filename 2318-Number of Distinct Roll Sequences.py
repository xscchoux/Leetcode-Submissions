class Solution:
    def distinctSequences(self, n: int) -> int:
        dp = [[[0 for i in range(0, 7)] for j in range(0, 7)] for _ in range(n+1)]
        kMod = 1000000007
        if n == 1:
            return 6
        
        def GCD(x, y):
            while y:
                x, y = y, x % y
            return abs(x)
        
        arr = [[0]*7 for i in range(7)]
        
        for i in range(1, 7):
            for j in range(1, 7):
                if GCD(i, j) == 1:
                    arr[i][j] = 1
        
        for i in range(1, 7):
            for j in range(1, 7):
                if i != j and arr[i][j] == 1:
                    dp[2][i][j] = 1        
        
        for idx in range(2, n):
            for i in range(1, 7):
                for p in range(1, 7):
                    if i != p and arr[i][p] == 1:
                        for pp in range(1, 7):
                            if i == pp:
                                continue
                            dp[idx+1][i][p] = (dp[idx+1][i][p] + dp[idx][p][pp])%kMod
                            
        return sum([dp[-1][i][j] for i in range(7) for j in range(7)])%kMod