class Solution {
public:
    vector<int> res;
    void dfs(int curr, int parent, unordered_map<int, vector<int>>& graph){
        for (int nxt:graph[curr]){
            if (nxt != parent){
                res.push_back(nxt);
                dfs(nxt, curr, graph);
            }
        }
    }
    
    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
        unordered_map<int, vector<int>> graph;
        for (vector<int> pairs:adjacentPairs){
            int u = pairs[0], v = pairs[1];
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        
        // find starting point
        int root = 0;
        for (auto &pair:graph){
            if (pair.second.size() == 1){
                root = pair.first;
                break;
            }
        }
        res.push_back(root);
        dfs(root, -1, graph);
        return res;
    }
};