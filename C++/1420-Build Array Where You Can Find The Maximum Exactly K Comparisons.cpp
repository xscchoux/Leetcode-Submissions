using LL = long long;
class Solution {
public:
    int n, m;
    int MOD = 1e9+7;
    vector<vector<vector<int>>> memo;
    
    int dfs(int idx, LL maxSoFar, int remain) {
        if (idx == n){
            if (remain == 0){
                return 1;
            }
            return 0;
        }

        if (memo[idx][maxSoFar][remain] != -1) return memo[idx][maxSoFar][remain];
        int res = 0;

        if (maxSoFar != 0) res = (maxSoFar*dfs(idx+1, maxSoFar, remain))%MOD;
        if (remain >= 1){
            for (int nxtMax = maxSoFar+1; nxtMax <= m; nxtMax++){
                res = (res + dfs(idx+1, nxtMax, remain-1))%MOD;
            }            
        }
        memo[idx][maxSoFar][remain] = res;
        return res;
    }
    
    int numOfArrays(int n, int m, int k) {
        this->n = n;
        this->m = m;  // define these two so n and m can be used in dfs() function
        memo = vector(n, vector(m+1, vector(k+1, -1)));
        return dfs(0, 0, k);
    }
};