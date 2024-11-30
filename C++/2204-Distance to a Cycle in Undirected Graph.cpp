class Solution {
public:
    vector<int> distanceToCycle(int n, vector<vector<int>>& edges) {
        vector<int> indegree(n, 0);
        vector<vector<int>> graph(n);
        for (auto &e:edges) {
            int u=e[0], v=e[1];
            indegree[u]++;
            indegree[v]++;
            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        queue<int> q;
        for (int i=0; i<n; i++) {
            if (indegree[i] == 1) q.push(i);
        }

        vector<int> visited(n, false);
        while (!q.empty()) {
            int curr = q.front();
            q.pop();
            visited[curr] = true;
            for (int nxt:graph[curr]) {
                if (visited[nxt]) continue;
                indegree[nxt]--;
                if (indegree[nxt] == 1) {
                    q.push(nxt);
                }
            }
        }

        queue<int> onCycle;
        vector<int> res(n, -1);
        for (int i=0; i<n; i++) {
            if (indegree[i] > 1) {
                onCycle.push(i);
                res[i] = 0;
            }
        }

        int step = 0;        
        while (!onCycle.empty()) {
            int length = onCycle.size();
            while (length-- > 0) {
                int curr = onCycle.front();
                onCycle.pop();
                res[curr] = step;
                for (int nxt:graph[curr]) {
                    if (res[nxt] != -1) continue;
                        onCycle.push(nxt);
                        res[nxt] = res[curr]+1;
                }
            }
            step++;
        }

        return res;
    }
};