class Solution {
public:
    long long maxProfit(vector<int>& prices, vector<int>& strategy, int k) {
        int N = prices.size();
        vector<long long> preSum(N+1, 0), preSumMul(N+1, 0);
        for (int i=0; i<N; i++) {
            preSum[i+1] = preSum[i] + prices[i];
        }

        for (int i=0; i<N; i++) {
            preSumMul[i+1] = preSumMul[i] + (long long)prices[i]*strategy[i];
        }

        long long res = preSumMul.back();

        for (int i=0; i<=N-k; i++) {
            res = max(res, preSumMul[i] +  (preSum[i+k] - preSum[i+k/2]) + (i+k==N?0:(preSumMul[N]-preSumMul[i+k])));
        }

        return res;
    }
};