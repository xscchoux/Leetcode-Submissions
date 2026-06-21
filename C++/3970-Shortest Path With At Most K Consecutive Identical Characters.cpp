// DFS TLE
// class Solution {
// public:
//     int k, n;
//     int res = INT_MAX;
//     void dfs(int curr, string& labels, vector<vector<pair<int, int>>>& graph, int edgeSum, char lastChar, int cnt) {
//         if (curr == n-1) {
//             res = min(res, edgeSum);
//             return;
//         }
//         char tmp = labels[curr];
//         labels[curr] = '#';
//         for (auto [nxt, weight]:graph[curr]) {
//             if (labels[nxt] == '#') continue;
//             if (labels[nxt] == lastChar) {
//                 if (cnt+1 > k) continue;
//                 dfs(nxt, labels, graph, edgeSum+weight, lastChar, cnt+1);
//             } else {
//                 dfs(nxt, labels, graph, edgeSum+weight, labels[nxt], 1);
//             }
//         }
//         labels[curr] = tmp;
//     }
//     int shortestPath(int n, vector<vector<int>>& edges, string labels, int k) {
//         this->k = k;
//         this->n = n;
//         vector<vector<pair<int, int>>> graph(n);
//         for (auto &e:edges) {
//             graph[e[0]].push_back({e[1], e[2]});
//         }

//         dfs(0, labels, graph, 0, labels[0], 1);

//         if (res == INT_MAX) res = -1;
//         return res;
//     }
// };


// Dijkstra
class Solution {
public:
    int shortestPath(int n, vector<vector<int>>& edges, string labels, int k) {
        vector<vector<int>> dist(n, vector<int>(k+1, INT_MAX));
        vector<vector<pair<int, int>>> graph(n);

        for (auto &e:edges) {
            graph[e[0]].push_back({e[1], e[2]});
        }

        priority_queue<array<int, 3>, vector<array<int, 3>>, greater<array<int, 3>>> pq;
        pq.push({0, 0, 1});  // {total weight, current, node, count}

        while (!pq.empty()) {
            auto arr = pq.top();
            pq.pop();
            int d = arr[0], curr = arr[1], cnt = arr[2];

            if (dist[curr][cnt] != INT_MAX) continue;
            dist[curr][cnt] = d;

            for (auto [nxt, w]:graph[curr]) {
                int nxtCnt = (labels[curr] == labels[nxt])?cnt+1:1;
                if (nxtCnt > k) continue;
                if (dist[nxt][nxtCnt] == INT_MAX) {
                    pq.push({d+w, nxt, nxtCnt});
                }
            }
        }
        int res = INT_MAX;
        for (int kk = 1; kk<=k; kk++) {
            res = min(res, dist[n-1][kk]);
        }

        return res == INT_MAX?-1:res;
    }
};