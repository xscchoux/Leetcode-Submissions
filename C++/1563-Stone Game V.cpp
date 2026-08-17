class Solution {
public:
    int rangeSum(int start, int end, vector<int>& preSum) {
        return preSum[end+1] - preSum[start];
    }
    int stoneGameV(vector<int>& stoneValue) {
        int N = stoneValue.size();
        if (N == 1) return 0;
        
        vector<int> preSum(N+1, 0);
        vector<vector<int>> dp(N, vector<int>(N, 0));

        for (int i=0; i<N; i++) {
            preSum[i+1] = preSum[i] + stoneValue[i];
        }

        for (int len = 2; len <= N; len++) {
            for (int i=0; i<=N-len; i++) {
                int j = i+len-1;
                for (int k=i+1; k<=j; k++) {

                    int leftRangeSum = rangeSum(i, k-1, preSum);
                    int rightRangeSum = rangeSum(k, j, preSum);
                    
                    if (leftRangeSum < rightRangeSum) {
                        dp[i][j] = max(dp[i][j], leftRangeSum + dp[i][k-1]);
                    } else if (leftRangeSum > rightRangeSum) {
                        dp[i][j] = max(dp[i][j], rightRangeSum + dp[k][j]);
                    } else {
                        dp[i][j] = max(dp[i][j], max(leftRangeSum + dp[i][k-1], leftRangeSum + dp[k][j]));
                    }
                }
            }
        }


        return dp[0][N-1];
    }
};