// Time complexity: O(E*k*t + n + E) = O(E*k*t + n)
class Solution {
public:
    int t;
    // O(E*k*t) states, E is the number of edges
    int dfs(int curr, int edgeSum, int kRemain, int t, vector<vector<pair<int, int>>>& graph, vector<vector<unordered_map<int, int>>>& memo) {
        if (kRemain == 0) {
            return edgeSum<t?edgeSum:-1;
        }

        if (memo[curr][kRemain].contains(edgeSum)) return memo[curr][kRemain][edgeSum];
        int res = -1;
        for (auto &[nxt, weight]:graph[curr]) {
            int nxtSum = weight + edgeSum;
            if (nxtSum >= t) continue;
            res = max(res, dfs(nxt, nxtSum, kRemain-1, t, graph, memo));
        }

        return memo[curr][kRemain][edgeSum] = res;
    }
    int maxWeight(int n, vector<vector<int>>& edges, int k, int t) {
        this->t = t;
        vector<vector<pair<int, int>>> graph(n);

        for (auto &e:edges) {   // O(E)
            graph[e[0]].push_back({e[1], e[2]});
        }

        vector<vector<unordered_map<int, int>>> memo(n, vector<unordered_map<int, int>>(k+1));

        int res = -1;
        for (int i=0; i<n; i++) {  // O(n) 
            res = max(res, dfs(i, 0, k, t, graph, memo));
        }

        return res;
    }
};