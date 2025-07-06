using PII = pair<int, int>;
class Solution {
public:
    int minTime(int n, vector<vector<int>>& edges) {
        // Dijkstra
        vector<vector<tuple<int, int, int>>> graph(n);
        for (auto &e:edges) {
            graph[e[0]].push_back({e[1], e[2], e[3]});
        }

        priority_queue<PII, vector<PII>, greater<>> pq;

        pq.push({0, 0});
        vector<int> minTime(n, INT_MAX);

        while (!pq.empty()) {
            auto [t, curr] = pq.top();
            pq.pop();
            if (curr == n-1) return t;
            if (t > minTime[curr]) continue;
            minTime[curr] = t;

            for (auto &[nxt, start, end]:graph[curr]) {
                int nxtTime = max(t+1, start+1);
                if (t <= end && nxtTime < minTime[nxt]) {
                    minTime[nxt] = nxtTime;
                    pq.push({nxtTime, nxt});
                }
            }
        }

        return -1;
    }
};