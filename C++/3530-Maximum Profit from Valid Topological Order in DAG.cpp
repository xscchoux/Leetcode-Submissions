class Solution {
public:
    int n;
    vector<int> dp;
    int dfs(int bitmask, vector<vector<int>>& graph, vector<int>& indegree, vector<int>& score, vector<int>& dp) {
        if (bitmask == (1<<n)-1) return 0;
        if (dp[bitmask] != -1) return dp[bitmask];

        int tot = 0;
        int processingOrder = __builtin_popcount(bitmask) + 1;
        for (int i=0; i<n; i++) {
            if ((bitmask&(1<<i)) == 0 && indegree[i] == 0) {
                // remove the item
                for (int child:graph[i]) {
                    indegree[child]--;
                }
                tot = max(tot, score[i]*processingOrder + dfs(bitmask^(1<<i), graph, indegree, score, dp));
                for (int child:graph[i]) {
                    indegree[child]++;
                }
            }
        }
        return dp[bitmask] = tot; 
    }
    int maxProfit(int n, vector<vector<int>>& edges, vector<int>& score) {
        this->n = n;
        vector<vector<int>> graph(n);
        vector<int> indegree(n, 0);
        for (auto &e:edges) {
            int u = e[0], v = e[1];
            graph[u].push_back(v);
            indegree[v]++;
        }

        dp.resize(1<<n, -1);
        return dfs(0, graph, indegree, score, dp);
    }
};