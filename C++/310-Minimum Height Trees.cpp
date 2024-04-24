class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if (edges.empty()) return {0};
        
        unordered_map<int, unordered_set<int>> graph;
        for (auto edge:edges) {
            int u = edge[0], v = edge[1];
            graph[u].insert(v);
            graph[v].insert(u);
        }
        
        queue<int> q;
        for (auto &kv:graph) {
            int k = kv.first;
            if (graph[k].size() == 1) q.push(k);
        }
        
        while (graph.size() > 2) {
            int length = q.size();
            while (length--) {
                int curr = q.front();
                q.pop();
                for (int nxt:graph[curr]) {
                    graph[nxt].erase(curr);
                    if (graph[nxt].size() == 1) {
                        q.push(nxt);
                    }
                }
                graph.erase(curr);
            }
        }
        
        vector<int> res;
        for (auto &kv:graph) {
            res.push_back(kv.first);
        }
        
        return res;
    }
};