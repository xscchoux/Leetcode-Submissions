class Solution {
public:
    int res = 0;
    int dfs(vector<vector<int>>& graph, int curr, int parent) {
        int tot = 0, prevCnt = -1;
        bool same = true;
        for (int nxt:graph[curr]) {
            if (nxt == parent) continue;
            int cnt = dfs(graph, nxt, curr);
            if (prevCnt != -1 && prevCnt != cnt) same = false;
            prevCnt = cnt;
            tot += cnt;
        }
        if (same) res++;
        return tot+1;
    }
    int countGoodNodes(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<vector<int>> graph(n+1);
        for (auto &edge:edges) {
            int u = edge[0], v = edge[1];
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        dfs(graph, 0, -1);
        return res;
    }
};