class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int N = arr.size();
        vector<int> dp(N+1, 0);
        
        for (int i=0; i<N; i++) {
            int mx = arr[i];
            for (int kk=0; kk<k; kk++) {
                if (kk > i) break;
                mx = max(mx, arr[i-kk]);
                dp[i+1] = max(dp[i+1], mx*(kk+1) + dp[i-kk]);
            }
        }
        
        return dp[N];
    }
};