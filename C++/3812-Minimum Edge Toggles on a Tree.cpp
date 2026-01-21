// Note that
// 1. A tree has no cycle
// 2. Unique path between two nodes
// 3. Toggling an edge only affect current node and the corresponding subtree

// Simple DFS solves this problem
class Solution {
public:
    vector<int> res;
    map<pair<int, int>, int> edge2Idx;
    void dfs(int curr, int parent, vector<vector<pair<int, int>>>& graph, string& start, string& target) {
        
        for (auto [nxt, idx]:graph[curr]) {
            if (nxt == parent) continue;
            dfs(nxt, curr, graph, start, target);
            if (start[nxt] != target[nxt]) {
                res.push_back(idx);
                start[nxt] = ('1' - start[nxt])+'0';
                start[curr] = ('1' - start[curr])+'0';
            }
        }

    }
    vector<int> minimumFlips(int n, vector<vector<int>>& edges, string start, string target) {
        // keep subtree nodes match target
        vector<vector<pair<int, int>>> graph(n);

        for (int i=0; i<edges.size(); i++) {
            graph[edges[i][0]].push_back({edges[i][1], i});
            graph[edges[i][1]].push_back({edges[i][0], i});
        }

        dfs(0, -1, graph, start, target);

        if (start[0] != target[0]) return {-1};
        sort(begin(res), end(res));

        return res;
    }
};