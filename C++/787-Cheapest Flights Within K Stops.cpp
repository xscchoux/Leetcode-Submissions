class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        unordered_map<int, vector<pair<int, int>>> graph;
        
        for (auto flight:flights) {
            graph[flight[0]].push_back({flight[1], flight[2]});
        }
        
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;
        unordered_map<int, int> visited;
        for (int i=0; i<n; i++) {
            visited[i] = k+1;
        }
        
        pq.push({0, src, 0});
        
        while (!pq.empty()) {
            auto [tot, curr, step] = pq.top();
            pq.pop();
            if (step > visited[curr]) continue;
            visited[curr] = step;
            if (curr == dst) return tot;
            if (step > k) continue;
            
            for (auto [nxt, cost]:graph[curr]) {
                pq.push({tot+cost, nxt, step+1});
            }
        }
        
        return -1;
    }
};