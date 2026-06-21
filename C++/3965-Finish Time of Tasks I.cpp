class Solution {
public:
    long long dfs(int curr, vector<vector<int>>& graph, vector<int>& baseTime) {
        if (graph[curr].empty()) {
            return baseTime[curr];
        }
        long long earliest = LLONG_MAX, latest = 0;
        
        for (int nxt:graph[curr]) {
            long long t = dfs(nxt, graph, baseTime);
            earliest = min(t, earliest);
            latest = max(t, latest);
        }

        return latest + (latest-earliest) + baseTime[curr];
    }
    long long finishTime(int n, vector<vector<int>>& edges, vector<int>& baseTime) {
        // note that the graph is directed
        vector<vector<int>> graph(n);
        for (auto &e:edges) {
            graph[e[0]].push_back(e[1]);
        }

        long long res = dfs(0, graph, baseTime);

        return res;
    }
};