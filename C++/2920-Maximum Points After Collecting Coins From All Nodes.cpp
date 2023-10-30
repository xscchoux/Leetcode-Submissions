class Solution {
public:
    int k;
    
    int dfs(int curr, int parent, int half_times, int max_half, vector<int>& coins, unordered_map<int, vector<int>>& graph, vector<vector<int>>& dp){
        if (dp[curr][half_times] != -1) return dp[curr][half_times];
        if (half_times == max_half) return 0;
        int val1 = (coins[curr] >> half_times) - k;
        int val2 = coins[curr] >> (half_times+1);
        
        for (int nxt:graph[curr]){
            if (nxt == parent) continue;
            
            int maxValue1 = dfs(nxt, curr, half_times, max_half, coins, graph, dp);
            int maxValue2 = dfs(nxt, curr, half_times+1, max_half, coins, graph, dp);
            
            val1 += maxValue1;
            val2 += maxValue2;
            
        }
        
        return dp[curr][half_times] = max(val1, val2);
    }
    
    int maximumPoints(vector<vector<int>>& edges, vector<int>& coins, int k) {
        this->k = k;
        unordered_map<int, vector<int>> graph;
        for (auto &edge:edges){
            int u = edge[0];
            int v = edge[1];
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        
        int max_half = 0;
        int mx = *max_element(coins.begin(), coins.end());
        while (mx > 0){
            mx >>= 1;
            max_half++;
        }
        
        int N = coins.size();
        vector<vector<int>> dp(N+1, vector(max_half+1, -1));
        return dfs(0, N, 0, max_half, coins, graph, dp);
    }
};