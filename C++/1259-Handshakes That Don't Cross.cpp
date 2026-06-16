class Solution {
public:
    int dp[1001], kMod = 1e9+7;
    long long dfs(int N) {
        if (dp[N] != -1) return dp[N];
        
        long long res = 0;
        int i=1;
        for (int j=i+1; j<=N; j+=2) {
            int diff1 = j-i-1, diff2 = N-j;
            res = (res + dfs(diff1)*dfs(diff2))%kMod;
        }
        return dp[N] = res;
    }
    int numberOfWays(int numPeople) {
        memset(dp, -1, sizeof(dp));
        dp[2] = dp[0] = 1;

        return dfs(numPeople);
    }
};