// Note that dp[curr][inverted][dist] is faster than dp[curr][dist][inverted]
// Put the most frequently changing index as the innermost vector (i.e., rightmost)

using LL = long long;
class Solution {
public:
    int k;
    LL dfs(int curr, int dist, int inverted, int parent, vector<int>& nums, vector<vector<int>>& graph, vector<vector<vector<LL>>>& dp) {
        if (dp[curr][inverted][dist] != LLONG_MIN/2) return dp[curr][inverted][dist];

        
        LL currNum = inverted?-nums[curr]:nums[curr];
        LL invertedCurrNum = (dist>=k?-currNum:LLONG_MIN);

        // Not to invert
        for (int nxt:graph[curr]) {
            if (nxt == parent) continue;
            currNum += dfs(nxt, min(dist+1, k), inverted, curr, nums, graph, dp);
        }

        // Invert
        if (dist >= k) {
            for (int nxt:graph[curr]) {
                if (nxt == parent) continue;
                invertedCurrNum += dfs(nxt, 1, 1-inverted, curr, nums, graph, dp);
            }      
        }

        return dp[curr][inverted][dist] = max(invertedCurrNum, currNum);
    }

    long long subtreeInversionSum(vector<vector<int>>& edges, vector<int>& nums, int k) {
        this->k = k;
        int N = nums.size();
        vector<vector<int>> graph(N);
        for (auto &e:edges) {
            graph[e[0]].push_back(e[1]);
            graph[e[1]].push_back(e[0]);
        }

        vector<vector<vector<LL>>> dp(N, vector<vector<LL>>(2, vector<LL>(k+1, LLONG_MIN/2)));

        return dfs(0, k, 0, -1, nums, graph, dp);
    }
};