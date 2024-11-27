// O(n&(n + queries.length))
class Solution {
public:
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        vector<int> dp(n);
        vector<vector<int>> from(n);
        for (int i=1; i<n; i++) {
            dp[i] = dp[i-1] + 1;
            from[i].push_back(i-1);
        }
        vector<int> res;
        for (auto &q:queries) {
            int u = q[0], v = q[1];
            from[v].push_back(u);
            for (int curr = v; curr < n; curr++) {
                for (int prev:from[curr]) {
                    dp[curr] = min(dp[curr], dp[prev] + 1);
                }
            }
            res.push_back(dp[n-1]);
        }

        return res;
    }
};