class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        using PDI = pair<double, int>;
        priority_queue<PDI, vector<PDI>> pq;
        vector<vector<PDI>> graph(n);
        vector<double> res(n, -1);

        for (int i=0; i<edges.size(); i++) {
            int u = edges[i][0], v = edges[i][1];
            double w = succProb[i];
            graph[u].push_back({w, v});
            graph[v].push_back({w, u});
        }
        
        pq.push({1, start_node});

        while (!pq.empty()) {
            auto [prob, idx] = pq.top();
            pq.pop();
            if (res[idx] != -1) continue;
            res[idx] = prob;

            for (auto &[p, nxt]:graph[idx]) {
                pq.push({prob*p, nxt});
            }
        }

        return res[end_node]>=0?res[end_node]:0;
    }
};