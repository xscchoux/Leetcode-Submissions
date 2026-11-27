class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        int N = items.size();
        vector<int> cnt(N, 0);

        for (int i=0; i<N; i++) {
            for (int j=0; j<N; j++) {
                if (i == j) continue;
                if (items[j][0]%items[i][0] == 0) {
                    cnt[i]++;
                }
            }
        }

        vector<int> dp(budget+1, -1);
        dp[0] = 0;

        for (int i=0; i<N; i++) {
            for (int j=budget; j-items[i][1] >=0; j--) {
                if (dp[j-items[i][1]] != -1) {
                    dp[j] = max(dp[j], dp[j-items[i][1]] + cnt[i] + 1);
                }
            }
        }


        for (int i=0; i<N; i++) {
            // items[i]
            for (int j=items[i][1]; j<=budget; j++) {
                if (dp[j-items[i][1]] != -1) {
                    dp[j] = max(dp[j], dp[j-items[i][1]]+1);
                }
            }
        }

        return *max_element(begin(dp), end(dp));
    }
};