using PII = pair<int, int>;
class Solution {
public:

    int minMaxWeight(int n, vector<vector<int>>& edges, int threshold) {
        int weight = -1;
        vector<vector<PII>> graph(n);

        for (auto &edge:edges) {
            graph[edge[1]].push_back({edge[0], edge[2]});
        }

        vector<bool> visited(n, false);

        priority_queue<PII, vector<PII>, greater<>> pq;
        pq.push({0, 0});

        while (!pq.empty()) {
            auto [w, idx] = pq.top();
            pq.pop();
            if (visited[idx]) continue;
            visited[idx] = true;
            weight = max(weight, w);
            for (auto [nxt, nxtWeight]:graph[idx]) {
                if (visited[nxt]) continue;
                pq.push({nxtWeight, nxt});
            }
        }

        for (int i=0; i<n; i++) {
            if (!visited[i]) return -1;
        }

        return weight;
    }
};