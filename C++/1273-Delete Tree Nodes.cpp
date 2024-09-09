class Solution {
public:
    tuple<int, int, int> dfs(int curr, vector<vector<pair<int, int>>>& graph, vector<int>& value) {
        int val = value[curr];
        int cnt = 1, toErase = 0;

        for (auto &[nxt, _]:graph[curr]) {
            auto [childVal, childCnt, childErase] = dfs(nxt, graph, value);
            val += childVal;
            cnt += childCnt;
            toErase += childErase;
        }
        if (val == 0) return {val, cnt, cnt};
        return {val, cnt, toErase};
    }
    int deleteTreeNodes(int nodes, vector<int>& parent, vector<int>& value) {
        vector<vector<pair<int, int>>> graph(nodes);
        for (int i=0; i<nodes; i++) {
            if (parent[i] == -1) continue;
            graph[parent[i]].push_back({i, value[i]});
        }

        return nodes - get<2>(dfs(0, graph, value));
    }
};