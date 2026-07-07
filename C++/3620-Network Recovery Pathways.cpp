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
            if (!online[u] || !online[v]) continue;
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


// binary search + DFS with memoization 
using PIL = pair<int, long>;
class Solution {
public:
    long long k;
    int N;
    long long dfs(int curr, unordered_map<int, vector<PIL>>& graph, vector<long long>& dp, int largestMin) {
        if (curr == N-1) return 0;
        if (dp[curr] != -1) {
            return dp[curr];
        }
        long long res = LLONG_MAX/2;
        for (auto& [nxt, w]:graph[curr]) {
            if (w < largestMin) continue;
            res = min(res, dfs(nxt, graph, dp, largestMin) + w);
        }
        return dp[curr] = res;
    }
    

    // edge cost should not be greater than maxEdge
    bool check(int curr, unordered_map<int, vector<PIL>>& graph, int largestMin) {
        vector<long long> dp(N, -1);
        long long maxPathScore = dfs(curr, graph, dp, largestMin);  // max path score 
        return maxPathScore <= k;

    }
    int findMaxPathScore(vector<vector<int>>& edges, vector<bool>& online, long long k) {
        this->k = k;
        this->N = online.size();
        int res = -1;
        if (edges.empty()) {
            return -1;
        }
        int maxEdge = 0, minEdge = INT_MAX;
        unordered_map<int, vector<PIL>> graph;
        for (auto &e:edges) {
            int u = e[0], v = e[1], w = e[2];
            if (!online[u] || !online[v]) continue;
            graph[u].push_back({v, w});

            maxEdge = max(maxEdge, w);
            minEdge = min(minEdge, w);
        }

        int left = minEdge, right = maxEdge;
        if (left > right) {   // no available edge
            return -1;
        }
        while (left + 1 < right) {
            int mid = left + (right-left)/2;
            if (check(0, graph, mid)) {
                left = mid;
            } else {
                right = mid;
            }
        }

        if (check(0, graph, right)) {
            return right;
        } else if (check(0, graph, left)) {
            return left;
        } else {
            return -1;
        }
    }
};