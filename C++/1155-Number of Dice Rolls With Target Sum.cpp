class Solution {
    int kMod = 1e9+7;
public:
    int dfs(vector<vector<int>>& memo, int n, int k, int remain){
        if (memo[n][remain] != -1) return memo[n][remain];
        if (n == 1){
            if (remain <= k && remain >= 1) return 1;
            else return 0;
        }
        
        int res = 0;
        for (int nxt=1; nxt <= k; nxt++){
            if (remain-nxt < n-1) break;
            res = (res + dfs(memo, n-1, k, remain-nxt))%kMod;
        }
        memo[n][remain] = res;
        return res;
    }
    
    int numRollsToTarget(int n, int k, int target) {
        vector<vector<int>> memo(n+1, vector<int>(target+1, -1));
        return dfs(memo, n, k, target);
    }
};