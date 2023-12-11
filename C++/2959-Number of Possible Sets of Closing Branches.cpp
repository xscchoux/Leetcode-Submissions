class Solution {
public:
    int numberOfSets(int n, int maxDistance, vector<vector<int>>& roads) {
        vector<vector<int>> graph(n, vector<int>(n, 1e5));  // distance between two branches
        int res = 0;
        for (vector<int> road:roads){
            int u=road[0], v=road[1], w=road[2];
            graph[u][v] = min(graph[u][v], w);
            graph[v][u] = min(graph[v][u], w);
        }
        
        for (int i=0; i<n; i++){
            graph[i][i] = 0;
        }
        
        for (int mask = 0; mask < (1<<n); mask++){
            vector<vector<int>> dp = graph;

            int maxDist = 0;
            // Floyd-Warshall
            for (int k=0; k<n; k++){
                if (!(mask & (1<<k))) continue;
                for (int i=0; i<n; i++){
                    if (!(mask & (1<<i))) continue;
                    for (int j=0; j<n; j++){
                        if (!(mask & (1<<j))) continue;
                        dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
                    }
                }
            }
            
            for (int i=0; i<n; i++){
                if (!(mask & (1<<i))) continue;
                for (int j=0; j<n; j++){
                    if (!(mask & (1<<j))) continue;
                    maxDist = max(maxDist, dp[i][j]);
                }
            }
            if (maxDist <= maxDistance) res++;
        }
        
        return res;
    }
};