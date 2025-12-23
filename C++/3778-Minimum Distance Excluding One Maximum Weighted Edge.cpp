// Note that we cannot use (pathsum-pathmax) as sorting condition in pq. Below is a counter example:

// 5
// [[0,1,2],[0,2,3],[2,3,50],[1,3,500],[3,4,100]]

using LII = tuple<long long, int, int>;
class Solution {
public:
    long long minCostExcludingMax(int n, vector<vector<int>>& edges) {
        this->n = n;
        vector<vector<pair<int, int>>> graph(n);
        vector<vector<bool>> visited(n, vector<bool>(2, false));
        priority_queue<LII, vector<LII>, greater<>> pq;

        for (auto &e:edges) {
            int u = e[0], v = e[1], w = e[2];
            graph[u].push_back({v, w});
            graph[v].push_back({u, w});
        }

        long long res = LLONG_MAX;
        pq.push({0, 0, 0}); // {dist, node, excluded}
        while (!pq.empty()) {
            auto [dist, node, excluded] = pq.top();
            pq.pop();
            if (visited[node][excluded]) continue;
            visited[node][excluded] = true;

            if (node == n-1) {
                if (excluded) {
                    return dist;
                }
                continue;
            }
            for (auto &[nxt, weight]:graph[node]) {
                if (excluded) {
                    if (!visited[nxt][excluded]) {
                        pq.push({dist+weight, nxt, excluded});
                    }
                } else {
                    if (!visited[nxt][1]) {
                        pq.push({dist, nxt, 1});
                    }
                    if (!visited[nxt][0]) {
                        pq.push({dist + weight, nxt, 0});
                    }
                }
            }
        }

        return -1;
    }
};