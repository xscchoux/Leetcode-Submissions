class Solution {
public:
    int res = 1;
    int maximumSubtreeSize(vector<vector<int>>& edges, vector<int>& colors) {
        unordered_map<int, vector<int>> graph;
        for (vector<int> edge:edges){
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }
        
        auto [tot, boolean] = helper(0, -1, graph, colors);
        
        return max(res, tot);
        
    }
    pair<int, bool> helper(int curr, int parent, unordered_map<int, vector<int>>& graph, vector<int>& colors) {
        int count = 1;
        bool sameColor = true;
        for (int nxt:graph[curr]) {
            if (nxt == parent) continue;
            auto [nxtCount, same] = helper(nxt, curr, graph, colors);
            res = max(res, nxtCount);
            if (colors[curr] != colors[nxt] || !same) {
                sameColor = false;
            }
            count += nxtCount;
        }
        if (!sameColor) return {1, false};
        return {count, true};
    }
};