class Solution {
public:
    int maxJumps(vector<int>& arr, int d) {
        int N = arr.size();

        vector<int> idx;
        for (int i=0; i<N; i++) idx.push_back(i);

        sort(begin(idx), end(idx), [&](int a, int b) {
            return arr[a] < arr[b];
        });
        
        vector<int> dp(N, 1);

        for (int curr:idx) {
            // check left
            for (int j=curr-1; j>=0 && curr-j <= d; j--) {
                if (arr[j] >= arr[curr]) break;
                dp[curr] = max(dp[curr], 1 + dp[j]);
            }
            // check right
            for (int j=curr+1; j<N && j-curr <= d; j++) {
                if (arr[j] >= arr[curr]) break;
                dp[curr] = max(dp[curr], 1 + dp[j]);
            }
        }

        return *max_element(begin(dp), end(dp));
    }
};