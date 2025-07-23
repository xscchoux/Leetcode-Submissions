// binary search + Dijkstra
using PIL = pair<int, long>;
class Solution {
public:
    long long k;
    int N;
    // edge cost should not be greater than maxEdge
    bool dijkstra(int curr, unordered_map<int, vector<PIL>>& graph, vector<bool>& online, int maxEdge) {
        using PLI = pair<long long, int>;
        priority_queue<PLI, vector<PLI>, greater<>> pq;
        vector<long long> res(N, -1);
        
        pq.push({0, curr});

        while (!pq.empty()) {
            auto [d, idx] = pq.top();
            pq.pop();
            if (res[idx] != -1) continue;
            res[idx] = d;

            for (auto &[nxt, cost]:graph[idx]) {
                 if (res[nxt] == -1 && cost >= maxEdge && online[nxt]) pq.push({d+cost, nxt});
            }
        }
        return res[N-1] != -1 && res[N-1] <= k;
    }
    int findMaxPathScore(vector<vector<int>>& edges, vector<bool>& online, long long k) {
        unordered_map<int, vector<PIL>> graph;
        this->k = k;
        this->N = online.size();

        for (auto &e:edges) {
            int u = e[0], v = e[1], w = e[2];
            graph[u].push_back({v, w});
        }

        int left = 0, right = 1e9;
        while (left + 1 < right) {
            int mid = left + (right-left)/2;
            if (dijkstra(0, graph, online, mid)) {
                left = mid;
            } else {
                right = mid;
            }
        }

        if (dijkstra(0, graph, online, right)) {
            return right;
        } else if (dijkstra(0, graph, online, left)) {
            return left;
        } else {
            return -1;
        }
    }
};