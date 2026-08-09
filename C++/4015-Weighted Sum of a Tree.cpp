class Solution {
public:
    long long tot = 0;
    int getHeight(int curr, vector<vector<int>>& graph, vector<int>& depth, int d) {
        int height = 1;
        depth[curr] = d;

        for (int nxt:graph[curr]) {
            height = max(height, 1 + getHeight(nxt, graph, depth, d+1));
        }

        return height;
    }
    long long weightedSum(vector<int>& parent, vector<int>& nums) {
        int N = parent.size();
        vector<int> depth(N);
        vector<vector<int>> graph(N);

        for (int i=0; i<N; i++) {
            if (parent[i] == -1) continue;
            graph[parent[i]].push_back(i);
        }
        
        // find max height and get depth of each node
        int maxHeight = getHeight(0, graph, depth, 1);

        // get sum
        for (int i=0; i<N; i++) {
            tot += (long long)nums[i]*(maxHeight-depth[i]+1);
        }

        return tot;
    }
};