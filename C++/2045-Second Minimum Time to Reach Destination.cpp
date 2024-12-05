// Dijkstra (slow)
using PII = pair<int, int>;
class Solution {
public:
    int secondMinimum(int n, vector<vector<int>>& edges, int time, int change) {
        vector<int> dist1(n+1, -1), dist2(n+1, -1);
        vector<vector<int>> graph(n+1);

        for (auto& e:edges) {
            int u = e[0], v = e[1];
            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        priority_queue<PII, vector<PII>, greater<>> pq;
        pq.push({0, 1});
        while (!pq.empty()) {
            auto [t, idx] = pq.top();
            pq.pop();
            if (dist1[idx] == -1) {
                dist1[idx] = t;
            } else if (dist2[idx] == -1 && t > dist1[idx]) {
                if (idx == n) return t;
                dist2[idx] = t;
            } else {
                continue;
            }

            t = ((t/change)%2)?((t/change)*change + change):t;
            
            for (int nxt:graph[idx]) {
                if (dist1[nxt] == -1) {
                    pq.push({t+time, nxt});
                } else if (dist2[nxt] == -1 && (t+time)>dist1[nxt]) {
                    pq.push({t+time, nxt});
                }
            }
        }

        return 0;
    }
};


// BFS is enough because we only need to count steps. The distances in queue are sorted, so we don't need a priority_queue
using PII = pair<int, int>;
class Solution {
public:
    int secondMinimum(int n, vector<vector<int>>& edges, int time, int change) {
        vector<int> dist1(n+1, INT_MAX), dist2(n+1, INT_MAX);
        vector<vector<int>> graph(n+1);

        for (auto& e:edges) {
            int u = e[0], v = e[1];
            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        queue<PII> q;  // {dist, idx}
        q.push({0, 1});
        dist1[1] = 0;

        while (!q.empty()) {
            auto [dist, curr] = q.front();
            q.pop();
            for (int nxt:graph[curr]) {
                if (dist+1 < dist1[nxt]) {
                    dist1[nxt] = dist+1;
                    q.emplace(dist+1, nxt);
                } else if (dist+1 < dist2[nxt] && dist+1 > dist1[nxt]) {  // note that the second minimum value is strictly larger than the minimum value
                    dist2[nxt] = dist+1;
                    q.emplace(dist+1, nxt);
                }
            }
        }

        int step = dist2[n];
        int t = 0;
        for (int s=1; s<=step; s++) {
            if ((t/change)&1) {
                t = (1+(t/change))*change + time;
            } else {
                t += time;
            }
        }

        return t;
    }
};