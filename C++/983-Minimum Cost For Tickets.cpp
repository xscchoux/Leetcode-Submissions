class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int N = days.size();
        vector<int> dp(N+1, INT_MAX);
        dp[0] = 0;
        for (int i=1; i<=N; i++) {
            for (int j=0; j<3; j++) {
                if (j==0) {
                    dp[i] = min(dp[i], dp[i-1]+costs[j]);
                } else {
                    int day = j==1?7:30;
                    auto it = lower_bound(begin(days), end(days), days[i-1]-day+1);
                    if (it == days.begin()) {
                        dp[i] = min(dp[i], costs[j]);
                    } else {
                        int idx = it - begin(days);
                        dp[i] = min(dp[i], costs[j] + dp[idx]);
                    } 
                }   
            }
        }

        return dp.back();
    }
};