class Solution {
public:
    int numWays(int n, int k) {
        // states:  0: without any, 1: has one, 2: has two
        int res = 0;
        unordered_map<int, int> dp {{0, 1}};
        
        for (int i=0; i<n; i++) {
            unordered_map<int, int> new_dp;
            for (auto &kv:dp) {
                if (kv.first == 0) {
                    new_dp[1] += k*dp[0];
                } else if (kv.first == 1) {
                    new_dp[2] += dp[1];
                    new_dp[1] += (k-1)*dp[1];
                } else {
                    new_dp[1] += (k-1)*dp[2];
                }
            }
            dp = new_dp;
        }
        
        for (auto &kv:dp) {
            res += kv.second;
        }
        
        return res;
    }
};