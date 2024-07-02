// TLE, O(n^2)
// class Solution {
// public:
//     int N;
//     int dp(vector<int>& preSum, int idx) {
//         if (idx == N-1) return preSum[N];
//         if (idx >= N) return 0;
//         int res = INT_MIN;
//         for (int cnt = 1 + (idx == 0); cnt <= N-idx; cnt++) {
//             res = max(res, preSum[idx+cnt] - dp(preSum, idx+cnt));
//         }
//         return res;
//     }
//     int stoneGameVIII(vector<int>& stones) {
//         this->N = stones.size();
//         vector<int> preSum(N+1, 0);
//         for (int i=0; i<N; i++) {
//             preSum[i+1] = preSum[i] + stones[i];
//         }
//         // dp(i) = preSum[i+1] - max(dp(i+1), dp(i+2), ..., dp(N-1))
//         return dp(preSum, 0);
//     }
// };


class Solution {
public:
    int N;
    int dfs(vector<int>& preSum, int idx, vector<int>& memo) {
        if (idx == N) return preSum[N];
        if (memo[idx] != -1) return memo[idx];

        memo[idx] = max(dfs(preSum, idx+1, memo), preSum[idx] - dfs(preSum, idx+1, memo));

        return memo[idx];
    }
    int stoneGameVIII(vector<int>& stones) {
        this->N = stones.size();
        vector<int> preSum(N+1, 0);
        for (int i=0; i<N; i++) {
            preSum[i+1] = preSum[i] + stones[i];
        }
        vector<int> memo(N, -1);

        // dp(i) = preSum[i+1] - max(dp(i+1), dp(i+2), ..., dp(N-1))
        // save the maximum dp(i) in memo
        
        return dfs(preSum, 2, memo);
    }
};