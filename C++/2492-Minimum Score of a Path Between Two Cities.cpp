class Solution {
public:
    int res = INT_MAX;
    void dfs(int curr, vector<bool>& visited, vector<vector<pair<int, int>>>& graph) {
        
        for (auto& [nxt, w]:graph[curr]) {
            res = min(res, w);
            if (visited[nxt]) continue;
            visited[nxt] = true;
            dfs(nxt, visited, graph);
        }
    }

    int minScore(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int, int>>> graph(n+1);
        vector<bool> visited(n+1, false);
        for (auto &r:roads) {
            graph[r[0]].push_back({r[1], r[2]});
            graph[r[1]].push_back({r[0], r[2]});
        }

        visited[1] = true;
        dfs(1, visited, graph);
        
        return res;
    }
};