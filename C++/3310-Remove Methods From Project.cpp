class Solution {
public:
    void dfs(int cur, vector<vector<int>>& graph, vector<int>& visited) {
        visited[cur] = 1;
        for (int nxt:graph[cur]) {
            if (!visited[nxt]) dfs(nxt, graph, visited);
        }
    }
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        vector<vector<int>> graph(n);
        for (auto &x:invocations) {
            int u = x[0], v = x[1];
            graph[u].emplace_back(v);
        }

        vector<int> visited(n, 0);
        dfs(k, graph, visited);

        bool touched = false;
        for (int i=0; i<n; i++) {
            if (!visited[i]) {
                for (int child:graph[i]) {
                    if (visited[child]) {
                        touched = true;
                        break;
                    }
                }
                if (touched) break;
            }
        }

        vector<int> res;

        if (!touched) {
            for (int i=0; i<n; i++) {
                if (visited[i]) continue;
                res.emplace_back(i);
            }
            return res;
        } else {
            for (int i=0; i<n; i++) res.emplace_back(i);
            return res;      
        }

    }
};