using PII = pair<int, int>;
class Solution {
public:
    int kMod = 1e9+7;
    void dfs(int curr, int val, vector<vector<PII>>& graph, vector<int>& res) {
        for (auto &[nxt, weight]:graph[curr]) {
            res[nxt] = (long long)val*weight%kMod;
            dfs(nxt, res[nxt], graph, res);
        }
    }
    vector<int> baseUnitConversions(vector<vector<int>>& conversions) {
        int N = conversions.size();
        vector<vector<PII>> graph(N+1);

        for (auto &c:conversions) {
            int u = c[0], v = c[1], w = c[2];
            graph[u].push_back({v, w});
        }

        vector<int> res(N+1, 1);
        dfs(0, 1, graph, res);

        return res;
    }
};