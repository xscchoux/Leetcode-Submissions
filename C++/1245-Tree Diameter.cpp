class Solution {
public:
    int treeDiameter(vector<vector<int>>& edges) {
        unordered_map<int, vector<int>> graph;
        int N = edges.size();
        vector<int> indegree(N+1);
        
        for (auto e:edges) {
            graph[e[0]].push_back(e[1]);
            graph[e[1]].push_back(e[0]);
            indegree[e[0]]++;
            indegree[e[1]]++;
        }
        
        int cnt = 0, level = 0, nodes = N+1;
        queue<int> q;
        for (auto &kv:graph) {
            if (indegree[kv.first] == 1) {
                q.push(kv.first);
            }
        }
        
        while (!q.empty()) {
            int length = q.size();
            if (nodes == 2) return level*2+1;
            if (nodes == 1) return level*2;
            while (length > 0) {
                int curr = q.front();
                q.pop();
                nodes--;
                length--;
                for (int nxt:graph[curr]) {
                    indegree[nxt]--;
                    if (indegree[nxt] == 1) {
                        q.push(nxt);
                    }
                }
            }
            level++;
        }
        return 0;
    }
};