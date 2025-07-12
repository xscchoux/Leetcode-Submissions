class Solution {
public:
    int res = 0;
    long long dfs(int curr, int parent, vector<vector<int>>& graph, vector<int>& cost) {
        vector<long long> childVal;
        for (int nxt:graph[curr]) {
            if (nxt == parent) continue;
            childVal.push_back(dfs(nxt, curr, graph, cost));
        }

        if (childVal.empty()){
            return cost[curr];
        }
        long long maxChildVal = *max_element(begin(childVal), end(childVal));        

        for (long long val:childVal) {
            if (val != maxChildVal) {
                res++;
            }
        }

        return maxChildVal + cost[curr];
    }
    int minIncrease(int n, vector<vector<int>>& edges, vector<int>& cost) {
        vector<vector<int>> graph(n);
        for (auto &e:edges) {
            int u = e[0], v = e[1];
            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        dfs(0, -1, graph, cost);

        return res;
    }
};