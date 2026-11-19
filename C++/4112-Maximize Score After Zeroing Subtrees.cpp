class Solution {
public:
    int dfs(int curr, vector<vector<int>>& graph, vector<int>& score, vector<int>& op) {
        int rootVal = score[curr];
        int smallest = INT_MAX, tot = 0;
        for (int child:graph[curr]) {
            int v = dfs(child, graph, score, op);
            smallest = min(smallest, v);
            tot += v;
        }

        if (smallest == INT_MAX) return rootVal;
        
        if (op[curr] == 1 || smallest < 0) {
            tot -= smallest;
        }

        return rootVal + tot;
    }
    int maxScore(vector<int>& parent, vector<int>& op, vector<int>& score) {
        int N = parent.size();
        vector<vector<int>> graph(N);

        for (int i=0; i<N; i++) {
            if (parent[i] == -1) continue;
            graph[parent[i]].push_back(i);
        }

        return dfs(0, graph, score, op);
    }
};