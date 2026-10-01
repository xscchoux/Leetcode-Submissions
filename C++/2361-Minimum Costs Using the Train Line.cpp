// O(N) time, O(N) space
class Solution {
public:
    vector<long long> minimumCosts(vector<int>& regular, vector<int>& express, int expressCost) {
        int N = regular.size();
        vector<vector<long long>> dp(N+1, vector<long long>(2, INT_MAX));
        vector<long long> res;
        dp[0][0] = 0;
        dp[0][1] = expressCost;

        for (int i=0; i<N; i++) {
            long long tmp0 = dp[i][0] + regular[i], tmp1 = dp[i][1] + express[i];

            dp[i+1][0] = min(tmp0, tmp1);

            dp[i+1][1] = min(tmp0 + expressCost, tmp1);

            res.push_back(min(dp[i+1][0], dp[i+1][1]));
        }

        return res;
    }
};


// O(1) space
class Solution {
public:
    vector<long long> minimumCosts(vector<int>& regular, vector<int>& express, int expressCost) {
        int N = regular.size();
        vector<vector<long long>> dp(2, vector<long long>(2, INT_MAX));
        vector<long long> res;
        dp[0][0] = 0;
        dp[0][1] = expressCost;

        for (int i=0; i<N; i++) {
            long long tmp0 = dp[i%2][0] + regular[i], tmp1 = dp[i%2][1] + express[i];

            dp[(i+1)%2][0] = min(tmp0, tmp1);

            dp[(i+1)%2][1] = min(tmp0 + expressCost, tmp1);

            res.push_back(min(dp[(i+1)%2][0], dp[(i+1)%2][1]));
        }

        return res;
    }
};