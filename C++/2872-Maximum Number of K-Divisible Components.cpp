class Solution {
public:
    int k;
    int toRemove = 0;
    int dfs(int curr, int parent, vector<vector<int>>& graph, vector<int>& values) {
        int tot = values[curr];
        for (int nxt:graph[curr]) {
            if (nxt == parent) continue;
            int nxtVal = dfs(nxt, curr, graph, values);
            if (nxtVal%k == 0) toRemove++;
            tot = (tot + nxtVal)%k;
        }
        return tot;
    }
    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
        this->k = k;
        vector<vector<int>> graph(n);
        for (auto &e:edges) {
            int u = e[0], v = e[1];
            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        dfs(0, -1, graph, values);
        return toRemove+1;
    }
};