class Solution {
public:
    vector<int> minimumTime(int n, vector<vector<int>>& edges, vector<int>& disappear) {
        vector<int> res(n, -1);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        vector<vector<pair<int, int>>> graph(n);

        for (auto edge:edges) {
            int u = edge[0], v = edge[1], w = edge[2];
            graph[u].push_back({v, w});
            graph[v].push_back({u, w});
        }

        pq.push({0, 0});
        while (!pq.empty()) {
            auto [t, curr] = pq.top();
            pq.pop();
            if (res[curr] != -1) continue;
            res[curr] = t;
            for (auto [nxt, weight]:graph[curr]) {
                if (res[nxt] != -1 || t + weight >= disappear[nxt]) continue;
                pq.push({t + weight, nxt});
            }
        }

        return res;
    }
};

// Dijkstra 2
class Solution {
public:
    vector<int> minimumTime(int n, vector<vector<int>>& edges, vector<int>& disappear) {
        vector<int> res(n, 1e9);
        res[0] = 0;
        priority_queue<array<int, 2>, vector<array<int, 2>>, greater<array<int, 2>>> pq;
        vector<vector<array<int, 2>>> graph(n);
        vector<bool> visited(n, false);

        for (auto edge:edges) {
            int u = edge[0], v = edge[1], w = edge[2];
            graph[u].push_back({v, w});
            graph[v].push_back({u, w});
        }

        pq.push({0, 0});
        while (!pq.empty()) {
            auto [t, curr] = pq.top();
            pq.pop();
            if (visited[curr] || t > res[curr]) continue;
            visited[curr] = true;
            for (auto [nxt, weight]:graph[curr]) {
                if (t + weight >= disappear[nxt]) continue;
                if (t + weight < res[nxt]) {
                    res[nxt] = t + weight;
                    pq.push({t + weight, nxt});
                }
            }
        }

        for (int i=0 ;i<res.size(); i++) {
            if (res[i] == 1e9) res[i] = -1;
        }

        return res;
    }
};