class Solution {
public:
    int minimumCost(int n, vector<vector<int>>& highways, int discounts) {
        using T = tuple<int, int, int>;
        priority_queue<T, vector<T>, greater<>> pq;  // dist, index, used discounts
        vector<vector<pair<int, int>>> graph(n);
        for (auto &h:highways) {
            int u = h[0], v = h[1], w = h[2];
            graph[u].push_back({v, w});
            graph[v].push_back({u, w});
        }

        vector<vector<int>> dist(n, vector<int>(discounts+1, INT_MAX/2));

        pq.push({0, 0, 0});
        while (!pq.empty()) {
            auto [d, ind, used] = pq.top();   
            // Don't write `auto &[d, ind, used] = pq.top()`. `auto &[d, ind, used] = pq.top()` can lead to unsafe access patterns, especially when elements are popped from the queue, as it can cause undefined behavior. Here I saw heap-use-after-free error when I write `auto &[d, ind, used] = pq.top()`
            pq.pop();
            if (dist[ind][used] != INT_MAX/2) continue;
            dist[ind][used] = d;
            for (auto &[nxt, weight]:graph[ind]) {
                if (used + 1 <= discounts && dist[nxt][used+1] == INT_MAX/2) {
                    if (used >=1 && dist[nxt][used-1] <= d+weight/2) continue;
                    pq.push({d+weight/2, nxt, used+1});
                }
                if (dist[nxt][used] == INT_MAX/2) {
                    if (used >=1 && dist[nxt][used-1] < d+weight) continue;
                    pq.push({d+weight, nxt, used});
                }
            }
        }

        int res = INT_MAX/2;
        for (int i=0; i<=discounts; i++) {
            res = min(res, dist[n-1][i]);
        }

        return (res == INT_MAX/2)?-1:res;
    }
};