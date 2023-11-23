using LL = long long;
class Solution {
public:
    int n;
    int kMod = 1e9+7;
    int dp[100001][2][3][2];
    
    LL dfs(int idx, int lCount, int eCount, int tCount){
        if (idx == n){
            if (tCount >= 1 && eCount >= 2 && lCount >= 1) return 1;
            return 0;
        }
        if (dp[idx][lCount][eCount][tCount] != -1) return dp[idx][lCount][eCount][tCount];
        
        LL res = 0;
        res = (res + dfs(idx+1, (lCount+1>1)?1:1, eCount, tCount))%kMod;
        res = (res + dfs(idx+1, lCount, (eCount+1>2)?2:eCount+1, tCount))%kMod;
        res = (res + dfs(idx+1, lCount, eCount, (tCount+1>1)?1:1))%kMod;
        
        res = (res + 23*dfs(idx+1, lCount, eCount, tCount))%kMod;
        dp[idx][lCount][eCount][tCount] = res;
        return res;
        
    }
    
    int stringCount(int n) {
        this->n = n;
        memset(dp, -1, sizeof(dp));
        int res = dfs(0, 0, 0, 0);
        
        return res;
    }
};