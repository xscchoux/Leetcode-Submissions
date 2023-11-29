class Solution {
public:
    pair<long, long> dfs(int curr, int parent, unordered_map<int, vector<int>>& graph, vector<int>& values){
        long healthySum = 0, subSum = 0;
        int currVal = values[curr];
        for (int nxt:graph[curr]){
            if (nxt == parent) continue;
            auto [healthyVal, subVal] = dfs(nxt, curr, graph, values);
            healthySum += healthyVal; // values picked from all healthy subtrees
            subSum += subVal;         // total value from all subtrees
        }
        return {subSum?max(currVal+healthySum, subSum):0 , subSum+currVal};
    }
    
    long long maximumScoreAfterOperations(vector<vector<int>>& edges, vector<int>& values) {
        unordered_map<int, vector<int>> graph;
        for (vector<int> edge:edges){
            int u = edge[0], v = edge[1];
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        
        return dfs(0, -1, graph, values).first;
    }
};