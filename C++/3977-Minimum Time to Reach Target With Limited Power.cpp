using TLLI = tuple<long long, long long, int>;
class Solution {
public:
    vector<long long> minTimeMaxPower(int n, vector<vector<int>>& edges, int power, vector<int>& cost, int source, int target) {
        priority_queue<TLLI, vector<TLLI>, greater<>> pq;

        vector<vector<long long>> elapsed(n, vector<long long>(power+1, LLONG_MAX));
        vector<vector<pair<int, int>>> graph(n);

        for (auto &e:edges) {
            int u = e[0], v = e[1], w = e[2];
            graph[u].push_back({v, w});
        }


        elapsed[0][power] = 0;
        pq.push({0, power, source});
        vector<long long> res = {LLONG_MAX, 0};


        while (!pq.empty()) {
            auto [time, powerRemain, curr] = pq.top();
            pq.pop();

            if (curr == target) {
                if (time > res[0] || (time == res[0] && powerRemain <= res[1])) {
                    continue;
                }
                res[0] = time;
                res[1] = powerRemain;
                continue;
            }

            if (res[0] != LLONG_MAX && time > res[0]) break;  // clever pruning

            if (elapsed[curr][powerRemain] < time) {
                continue;
            }
            if (powerRemain < cost[curr]) {
                continue;
            }

            for (auto [nxt, tIncrease]:graph[curr]) {
                if (time + tIncrease >= elapsed[nxt][powerRemain-cost[curr]]) {
                    continue;
                }
                elapsed[nxt][powerRemain-cost[curr]] = time + tIncrease;
                pq.push({time+tIncrease, powerRemain-cost[curr], nxt});
            }
        }

        if (res[0] == LLONG_MAX) {
            return {-1, -1};
        }
        return res;
    }
};