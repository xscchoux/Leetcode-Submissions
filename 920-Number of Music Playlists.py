class Solution:
    def numMusicPlaylists(self, n: int, goal: int, k: int) -> int:
        
# Bottom-up DP
        hmap = {0:1} # k different values: how many arrays have k different values
        kMod = 10**9+7
        
        for _ in range(goal):
            tmp = defaultdict(int)
            for key, val in hmap.items():
                if key > k:
                    tmp[key] = (tmp[key] + val*(key-k))%kMod
                tmp[key+1] = (tmp[key+1] + val*(n-key))%kMod
            hmap = tmp
        
        return hmap[n]
                    
# Top-down DP
        kMod = 10**9+7
        
        def dfs(goalIdx):
            if goalIdx == 0:
                return {0:1}
            curr = defaultdict(int)
            for key, val in dfs(goalIdx-1).items():
                if key > k:
                    curr[key] = (curr[key] + val*(key-k))%kMod
                curr[key+1] = (curr[key+1] + val*(n-key))%kMod
            return curr
            
        return dfs(goal)[n]
    
    
# Bottom up DP2
        # dp[i][j] = number of combinations that put numbers from index 0 to index i, with j distinct numbers
        dp = [[-1 for _ in range(n+1)] for _ in range(goal+1)]
        dp[0][0] = 1
        kMod = 10**9+7
        
        for i in range(1, goal+1):
            for j in range(n+1):
                if dp[i][j] != -1:
                    if j > k:
                        dp[i][j] = (dp[i][j] + dp[i-1][j]*(j-k))%kMod
                    dp[i][j+1] = (dp[i][j+1] + dp[i-1][j]*(n-j))%kMod
        return dp[-1][n]