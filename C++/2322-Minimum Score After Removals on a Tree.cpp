class Solution {
public:
    int res = 1e8, N;
    int sumXOR = 0;
    int getScore(int v1, int v2, int v3) {
        return max(v1, max(v2, v3)) - min(v1, min(v2, v3));
    }
    int dfs2(int curr, int parent, int otherXOR, int source, vector<int>& nums, vector<vector<int>>& graph) {
        int currXOR = nums[curr];
        for (int nxt:graph[curr]) {
            if (nxt == parent) continue;
            currXOR ^= dfs2(nxt, curr, otherXOR, source, nums, graph);
        }
        if (parent != source) {
            res = min(res, getScore(otherXOR, currXOR, sumXOR^otherXOR^currXOR));
        }

        return currXOR;
    }
    int dfs(int curr, int parent, vector<int>& nums, vector<vector<int>>& graph) {
        int currVal = nums[curr];
        for (int nxt:graph[curr]) {
            if (nxt == parent) continue;
            currVal ^= dfs(nxt, curr, nums, graph);
        }
        for (int nxt:graph[curr]) {
            if (nxt == parent) {
                dfs2(parent, curr, currVal, curr, nums, graph);  // explore the other tree starting with parent node
            }
        }

        return currVal;
    }
    int minimumScore(vector<int>& nums, vector<vector<int>>& edges) {
        this->N = nums.size();
        vector<vector<int>> graph(N);

        for (auto &e:edges) {
            int u = e[0], v = e[1];
            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        for (int num:nums) {
            sumXOR ^= num;
        }

        dfs(0, -1, nums, graph);
        

        return res;
    }
};