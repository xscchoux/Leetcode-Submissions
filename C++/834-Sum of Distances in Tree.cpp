class Solution {
public:
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        vector<int> res(n, 0);
        vector<int> subCount(n, 0);
        vector<vector<int>> graph(n);

        for (auto &edge:edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }

        function<int(int, int)> dfs = [&](int curr, int prev) {   // cannot use auto here
            for (int &nxt : graph[curr]) {
                if (nxt == prev) continue;
                subCount[curr] += dfs(nxt, curr);
                res[curr] += subCount[nxt] + res[nxt];
            }
            subCount[curr]++;
            return subCount[curr];
        };

        function<void(int, int)> dfs2 = [&](int curr, int prev) {   // cannot use auto here
            for (int &nxt:graph[curr]) {
                if (nxt == prev) continue;
                res[nxt] = res[curr] + (n-subCount[nxt]) - subCount[nxt];  // res of parent + (added) - (substracted)
                dfs2(nxt, curr);
            }
        };

        dfs(0, -1);
        dfs2(0, -1);

        return res;
    }
};