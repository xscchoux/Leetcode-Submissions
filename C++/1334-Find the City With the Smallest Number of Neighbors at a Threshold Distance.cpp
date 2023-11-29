class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> dp(n+1, vector<int>(n+1, 10001));
        for (auto edge:edges){
            int u = edge[0], v = edge[1], w = edge[2];
            dp[u][v] = w;
            dp[v][u] = w;
        }
        for (int i=0; i<n; i++){
            dp[i][i] = 0;
        }
        
        
        for (int k = 0; k < n; k++){
            for (int i=0; i<n; i++){
                for (int j=0; j<n; j++){
                    dp[i][j] = min(dp[i][j], dp[i][k]+dp[k][j]);
                }
            }
        }
        
        int cnt = n;
        int res = n;
        for (int i=n-1; i>=0; i--){
            int tmp = 0;
            for (int j=0; j<n; j++){
                if (i!=j && dp[i][j] <= distanceThreshold) tmp++;
            }
            if (tmp < cnt) {
                cnt = tmp;
                res = i;
            }
        }
        
        return res;
    }
};