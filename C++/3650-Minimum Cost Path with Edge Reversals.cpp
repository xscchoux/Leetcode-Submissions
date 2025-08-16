using PII = pair<int, int>;
class Solution {
public:
    int minCost(int n, vector<vector<int>>& edges) {
        vector<vector<PII>> graph(n);
        for (auto &e:edges) {
            int u = e[0], v = e[1], w = e[2];
            graph[u].push_back({v, w});
            graph[v].push_back({u, 2*w});
        }

        vector<bool> seen(n, false);
        priority_queue<PII, vector<PII>, greater<>> pq;
        pq.push({0, 0});

        while (!pq.empty()) {
            auto [d, curr] = pq.top();
            pq.pop();
            if (curr == n-1) return d;
            if (seen[curr]) continue;
            seen[curr] = true;

            for (auto &[nxt, weight]:graph[curr]) {
                if (seen[nxt]) continue;
                pq.push({d+weight, nxt});
            }
        }

        return -1;
    }
};