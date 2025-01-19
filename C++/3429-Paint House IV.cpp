using LL = long long;
class Solution {
public:
    int n;
    LL dfs(int idx, int c1, int c2, vector<vector<int>>& cost, vector<vector<vector<LL>>>& dp) {
        if (idx == n/2) return 0;
        if (dp[idx][c1][c2] != -1) return dp[idx][c1][c2];

        LL curr = cost[idx][c1] + cost[n-idx-1][c2];
        LL toAdd = LLONG_MAX;
        
        for (int nc1=0; nc1<3; nc1++) {
            for (int nc2=0; nc2<3; nc2++) {
                if (nc1 == nc2 || nc1 == c1 || nc2 == c2) continue;
                    toAdd = min(toAdd, dfs(idx+1, nc1, nc2, cost, dp));
            }
        }

        return dp[idx][c1][c2] = curr+toAdd;
    }

    long long minCost(int n, vector<vector<int>>& cost) {
        this->n = n;
        vector<vector<vector<LL>>> dp(n/2, vector<vector<LL>>(3, vector<LL>(3, -1)));
        LL res = LLONG_MAX;
        for (int c1=0; c1<3; c1++) {
            for (int c2=0; c2<3; c2++) {
                if (c1 == c2) continue;
                    res = min(res, dfs(0, c1, c2, cost, dp));
            }
        }
        return res;
    }
};