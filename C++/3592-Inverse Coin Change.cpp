// https://www.youtube.com/watch?v=58MxA96KqwQ
// O(n^2) DP
class Solution {
public:
    vector<int> findCoins(vector<int>& numWays) {
        int N = numWays.size();
        vector<int> dp(N+1, 0), res;
        dp[0] = 1;
        numWays.insert(begin(numWays), 0);

        for (int num=1; num<=N; num++) {
            if (dp[num] == numWays[num]) {
                continue;
            }
            res.push_back(num);
            for (int i=num; i<=N; i++) {
                dp[i] = dp[i] + dp[i-num];
            }
        }

        for (int i=1; i<=N; i++) {
            if (dp[i] != numWays[i]) return {};
        }

        return res;
    }
};