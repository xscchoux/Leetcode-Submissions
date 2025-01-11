// O(N*(N+R)*logN), R is the number of roads (edges)
// Dijkstra
using LL = long long;
class Solution {
public:
    vector<long long> minCost(int n, vector<vector<int>>& roads, vector<int>& appleCost, int k) {
        vector<vector<pair<int, int>>> graph(n+1);
        for (auto &road:roads) {
            int u = road[0], v = road[1], w = road[2];
            graph[u].push_back({v, w});
            graph[v].push_back({u, w});
        }
        
        vector<LL> res(n, 0);

        for (int i=1; i<=n; i++) {
            vector<LL> dist(n+1, LLONG_MAX/2);
            priority_queue<pair<int, LL>, vector<pair<int, LL>>, greater<>> pq;
            pq.push({0, i});
            while (!pq.empty()) {
                auto [d, idx] = pq.top();
                pq.pop();
                if (dist[idx] < LLONG_MAX/2) continue;
                dist[idx] = d;
                for (auto &[nxt, weight]:graph[idx]) {
                    if (dist[nxt] < LLONG_MAX/2) continue;
                    pq.push({ d+weight*(1+k), nxt});
                }
            }

            LL minDist = LLONG_MAX/2;
            for (int j=1; j<=n; j++) {
                minDist = min(minDist, dist[j] + appleCost[j-1]);
            }
            res[i-1] = minDist;
        }

        return res;
    }
};



// (n+r)*log(n+r)
// clever priority queue solution, modified dijkstra
using LL = long long;
class Solution {
public:
    vector<long long> minCost(int n, vector<vector<int>>& roads, vector<int>& appleCost, int k) {
        vector<vector<pair<int, int>>> graph(n+1);
        for (auto &road:roads) {
            int u = road[0], v = road[1], w = road[2];
            graph[u-1].push_back({v-1, w});
            graph[v-1].push_back({u-1, w});
        }
        
        vector<LL> res(begin(appleCost), end(appleCost));

        priority_queue<pair<LL, int>, vector<pair<LL, int>>, greater<>> pq;
        for (int i=0; i<n; i++) {
            pq.push({appleCost[i], i});
        }

        while (!pq.empty()) {
            auto [currCost, currIdx] = pq.top();
            pq.pop();

            if (currCost > res[currIdx]) continue;

            for (auto &[nxt, weight]:graph[currIdx]) {
                if (currCost + (k+1)*weight < res[nxt]) {
                    res[nxt] = currCost + (k+1)*weight;
                    pq.push({currCost + (k+1)*weight, nxt});
                }
            }
        }

        return res;
    }
};