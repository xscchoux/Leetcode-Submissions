using PII = pair<int, int>;

class Solution {
public:
    int dijkstra(int n, int source, int destination,
                    const vector<vector<pair<int, int>>>& graph) {
        vector<int> minDistance(n, 2e9);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>>
            minHeap;

        minDistance[source] = 0;
        minHeap.emplace(0, source);

        while (!minHeap.empty()) {
            auto [d, u] = minHeap.top();
            minHeap.pop();

            if (d > minDistance[u]) continue;

            for (const auto& [v, weight] : graph[u]) {
                if (d + weight < minDistance[v]) {
                    minDistance[v] = d + weight;
                    minHeap.emplace(minDistance[v], v);
                }
            }
        }

        return minDistance[destination];
    }

    // int dijkstra(int n, int source, int destination, const vector<vector<PII>>& graph) {
    //     priority_queue<PII, vector<PII>, greater<>> pq;
    //     pq.push({0, source});
    //     vector<int> dist(n, 2e9);
        
    //     while (!pq.empty()) {
    //         auto [d, curr] = pq.top();
    //         pq.pop();
            
    //         if (dist[curr] != 2e9) continue;
    //         dist[curr] = d;
    //         if (curr == destination) break;

    //         for (auto &[nxt, w]:graph[curr]) {
    //             if (dist[nxt] == 2e9) pq.push({d+w, nxt});
    //         }
    //     }
        
    //     return dist[destination];
    // }

    vector<vector<int>> modifiedGraphEdges(int n, vector<vector<int>>& edges, int source, int destination, int target) {
        vector<vector<PII>> graph(n);
        for (int j=0; j<edges.size(); j++) {
            int u = edges[j][0], v = edges[j][1], w = edges[j][2];
            if (w != -1) {
                graph[u].push_back({v, w});
                graph[v].push_back({u, w});
            }
        }

        int dist0 = dijkstra(n, source, destination, graph);
        if (dist0 < target) return vector<vector<int>>();
        bool matched = (dist0 == target);

        for (auto &edge:edges) {
            if (edge[2] != -1) continue;
            graph[edge[0]].push_back({edge[1], 1});
            graph[edge[1]].push_back({edge[0], 1});

            if (!matched) {
                int dist = dijkstra(n, source, destination, graph);
                if (dist <= target) {
                    matched = true;
                    int diff = target - dist;
                    edge[2] = 1 + diff;
                } else {
                    edge[2] = 1;
                }
            } else {
                edge[2] = 2e9;
            }
        }

        return matched?edges:vector<vector<int>>();
    }
};