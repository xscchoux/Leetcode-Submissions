// Top-Down DP
class Solution {
public:
    vector<vector<int>> memo;
    int n;
    
    int paintWalls(vector<int>& cost, vector<int>& time) {
        n = cost.size();
        memo = vector(n+1, vector(n+1, -1)); // memo[current index][remain walls] = cost
        return dfs(0, n, cost, time);
    }
    
    int dfs(int idx, int remain, vector<int>& cost, vector<int>& time){
        if (remain <= 0) return 0;
        if (idx == cost.size()) return 1e9;
        
        if (memo[idx][remain] != -1) return memo[idx][remain];
        
        int noPick = dfs(idx+1, remain, cost, time);
        int pick = cost[idx] + dfs(idx+1, remain - 1 - time[idx], cost, time);
        memo[idx][remain] = min(noPick, pick);
        return memo[idx][remain];
    }
};


// Bottom-Up DP
class Solution {
public:
    int paintWalls(vector<int>& cost, vector<int>& time) {
        int n = cost.size();
        vector<double> dp = vector(n+1, 1e9);
        dp[0] = 0;
        
        for (int idx = 0; idx < cost.size(); idx++){
            for (int j = n; j >= 1; j--){
                dp[j] = min(dp[j], cost[idx] + dp[max(0, j-1-time[idx])]);
            }
        }
        
        return dp[dp.size()-1];
    }
};