class Solution {
public:
    vector<int> res;
    int N;
    int dfs1(vector<vector<int>>& graph, int curr, int parent, vector<multiset<pair<int, int>>>& dp) {

        for (int nxt:graph[curr]) {
            if (nxt == parent) continue;
            int dist = (nxt%2?1:2) + dfs1(graph, nxt, curr, dp);
            dp[curr].insert({dist, nxt});
            if (dp[curr].size() > 2) {
                dp[curr].erase(dp[curr].begin());
            }
        }

        return (*dp[curr].rbegin()).first;
    }
    // tree re-rooting
    void dfs2(vector<vector<int>>& graph, int curr, int parent, vector<multiset<pair<int, int>>>& dp, int timeFromParent) {
        res[curr] = max(timeFromParent, (*dp[curr].rbegin()).first);

        for (int nxt:graph[curr]) {
            if (nxt == parent) continue;
            int toParent = (curr%2?1:2) + timeFromParent; // the time it takes: nxt->curr->parent 
            int toOtherChild = (curr%2?1:2) + ((*dp[curr].rbegin()).second == nxt?(*dp[curr].begin()).first:(*dp[curr].rbegin()).first); // the time it takes: nxt->curr->(curr's child other than nxt)
            dfs2(graph, nxt, curr, dp, max(toParent, toOtherChild));
        }

    }
    vector<int> timeTaken(vector<vector<int>>& edges) {
        this->N = edges.size()+1;
        vector<vector<int>> graph(N);
        res.resize(N);
        for (auto &e:edges) {
            int u = e[0], v = e[1];
            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        vector<multiset<pair<int, int>>> dp(N, multiset<pair<int, int>>{{0, -1}, {0, -1}});

        dfs1(graph, 0, -1, dp);
        dfs2(graph, 0, -1, dp, 0);

        return res;
    }
};