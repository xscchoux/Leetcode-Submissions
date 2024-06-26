class Solution {
public:
    unordered_map<int, vector<int>> coprimes;
    void dfs(vector<int>& nums, int curr, int parent, int level, unordered_map<int, vector<pair<int, int>>>& visited, unordered_map<int, vector<int>>& graph, vector<int>& res) {
        int maxLevel = -1;

        for (int coprime:coprimes[nums[curr]]) {
            if (!visited[coprime].empty() && visited[coprime].back().second > maxLevel) {
                maxLevel = visited[coprime].back().second;
                res[curr] = visited[coprime].back().first;
            }
        }

        visited[nums[curr]].push_back({curr, level});
        for (int nxt:graph[curr]) {
            if (nxt == parent) continue;
            dfs(nums, nxt, curr, level+1, visited, graph, res);
        }
        visited[nums[curr]].pop_back();
    }
    vector<int> getCoprimes(vector<int>& nums, vector<vector<int>>& edges) {
        int N = nums.size();
        vector<int> res(N, -1);
        unordered_set<int> numSet(nums.begin(), nums.end());

        for (int n1:numSet) {
            for (int n2:numSet) {
                if (__gcd(n1, n2) == 1) {
                    coprimes[n1].push_back(n2);
                }
            }
        }

        unordered_map<int, vector<int>> graph;
        for (auto &edge:edges) {
            int u = edge[0], v = edge[1];
            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        unordered_map<int, vector<pair<int, int>>> visited;
        dfs(nums, 0, -1, 0, visited, graph, res);

        return res;
    }
};