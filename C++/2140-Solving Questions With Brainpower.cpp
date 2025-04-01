// basic top-down solution
class Solution {
public:
    int N;
    long long dfs(int idx, vector<vector<int>>& questions, vector<long long>& memo) {
        if (idx >= N) return 0;
        if (memo[idx] != -1) return memo[idx];
        // skip
        long long res = dfs(idx+1, questions, memo);
        // take
        res = max(res, questions[idx][0] + dfs(idx+questions[idx][1]+1, questions, memo));

        return memo[idx] = res;
    }
    long long mostPoints(vector<vector<int>>& questions) {
        this->N = questions.size();
        vector<long long> memo(N, -1);
        return dfs(0, questions, memo);
    }
};


// clever bottom-up solution
class Solution {
public:
    long long mostPoints(vector<vector<int>>& questions) {
        int N = questions.size();
        vector<long long> dp(N, 0);
        dp[N-1] = questions[N-1][0];

        for (int i=N-2; i>=0; i--) {
            long long currMax = questions[i][0];
            if ( (i + questions[i][1] + 1) < N) {
                currMax += dp[i + questions[i][1] + 1];
            }
            dp[i] = max(currMax, dp[i+1]);
        }

        return dp[0];
    }
};