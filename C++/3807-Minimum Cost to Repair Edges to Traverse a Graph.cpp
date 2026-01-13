class Solution {
public:
    int k, n;
    bool isOK(int money, vector<vector<pair<int, int>>>& graph) {
        vector<bool> visited(n, false);
        visited[0] = true;
        queue<pair<int, int>> q; // {current node, steps}
        q.push({0, 0});
        
        while (!q.empty()) {
            auto [curr, step] = q.front();
            q.pop();
            if (curr == n-1) return true;    
            if (step == k) continue;

            for (auto [nxt, weight]:graph[curr]) {
                if (visited[nxt]) continue;
                if (weight > money) {
                    continue;
                }
                visited[nxt] = true;
                q.push({nxt, step+1});
            }
        }

        return false;
    }
    int minCost(int n, vector<vector<int>>& edges, int k) {
        this->k = k;
        this->n = n;
        long long left = 1, right = 1e9;
        vector<vector<pair<int, int>>> graph(n);

        for (auto &e:edges) {
            graph[e[0]].push_back({e[1], e[2]});
            graph[e[1]].push_back({e[0], e[2]});
        }

        while (left + 1 < right) {
            long long mid = left + (right-left)/2;
            if (isOK(mid, graph)) {
                right = mid;
            } else {
                left = mid;
            }
        }

        if (isOK(left, graph)) {
            return left;
        } else if (isOK(right, graph)) {
            return right;
        }

        return -1;
    }
};