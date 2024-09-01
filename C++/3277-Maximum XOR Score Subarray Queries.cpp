class Solution {
public:
    vector<int> maximumSubarrayXor(vector<int>& nums, vector<vector<int>>& queries) {
    // XOR([a,b,c]) -> XOR([a^b, b^c]) -> [a^b^b^c]
    // XOR([a,b,c,d]) -> XOR([a^b, b^c, c^d]) -> XOR([a^b^b^c, b^c^c^d]) -> [a^b^b^b^c^c^c^d]
    // Then we can tell XOR([a,b,c,d]) is the same as XOR([a,b,c])^XOR([b,c,d])
    // dp[st][end] = dp[st][end-1]^dp[st+1][end]

        int N = nums.size();
        vector<vector<int>> dp(N, vector<int>(N, 0));

        for (int len=1; len<=N; len++) {
            for (int st=0; st<N; st++) {
                if (len == 1) dp[st][st] = nums[st];
                else {
                    int end = st+len-1;
                    if (end >= N) break;
                    dp[st][end] = dp[st][end-1]^dp[st+1][end];
                }
            }
        }

        // makes dp[i][j] provide the max value for all subarrays starting with i and the ending position is <=j
        for (int i=0; i<N; i++) {
            for (int j=i+1; j<N; j++) {
                dp[i][j] = max(dp[i][j], dp[i][j-1]);
            }
        }

        // Further makes dp[i][j] provide the max value for all subarrays [i..j]
        for (int i=N-2; i>=0; i--) {
            for (int j=0; j<N; j++) {
                dp[i][j] = max(dp[i][j], dp[i+1][j]);
            }
        }

        vector<int> res;
        for (auto &q:queries) {
            int u = q[0], v = q[1];
            res.push_back(dp[u][v]);
        }

        return res;
    }
};



// A better way to get max value for dp[i][j]
class Solution {
public:
    vector<int> maximumSubarrayXor(vector<int>& nums, vector<vector<int>>& queries) {
        int N = nums.size();
        vector<vector<int>> dp(N, vector<int>(N, 0));

        for (int len=1; len<=N; len++) {
            for (int st=0; st<N; st++) {
                if (len == 1) dp[st][st] = nums[st];
                else {
                    int end = st+len-1;
                    if (end >= N) break;
                    dp[st][end] = dp[st][end-1]^dp[st+1][end];
                }
            }
        }

        for (int len=2; len<=N; len++) {
            for (int st=0; st<N; st++) {
                int end = st+len-1;
                if (end >= N) break;
                dp[st][end] = max({dp[st][end], dp[st][end-1], dp[st+1][end]});
            }
        }        

        vector<int> res;
        for (auto &q:queries) {
            int u = q[0], v = q[1];
            res.push_back(dp[u][v]);
        }

        return res;
    }
};

// This solution is also pretty good

https://leetcode.com/problems/maximum-xor-score-subarray-queries/solutions/5719042/python-write-all-xor-scores/