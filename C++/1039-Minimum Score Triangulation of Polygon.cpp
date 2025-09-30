class Solution {
public:
    int dfs(int first, int end, vector<int>& values, vector<vector<int>>& memo) {
        if (first + 1 == end) return 0;

        if (memo[first][end] != -1) return memo[first][end];

        int res = INT_MAX;
        for (int k=first+1; k<end; k++) {
            res = min(res, values[first]*values[k]*values[end] + dfs(first, k, values, memo) + dfs(k, end, values, memo));
        }

        return memo[first][end] = res;
    }
    int minScoreTriangulation(vector<int>& values) {
        int N = values.size();
        vector<vector<int>> memo(N, vector<int>(N, -1));

        return dfs(0, N-1, values, memo);

    }
};


// Bottom-up DP, calculate smaller shapes first, clever but harder to understand
class Solution {
public:
    int minScoreTriangulation(vector<int>& values) {
        int N = values.size();
        vector<vector<int>> dp(N, vector<int>(N, 0));

        for (int d=2; d<N; d++) {
            for (int start=0; start<N-d; start++) {
                int end = (start+d); // maximum value is N-1
                int weight = values[start]*values[end];
                int res = INT_MAX;
                for (int k=start+1; k<start+d; k++) {
                    res = min(res, weight*values[k] + dp[start][k] + dp[k][end]);
                }
                dp[start][end] = res;
            }
        }

        return dp[0][N-1];
    }
};