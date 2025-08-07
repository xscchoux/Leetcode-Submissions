class Solution {
public:
    int tot = 0, N;
    int dp[1000][1000];
    int cal1(vector<vector<int>>& fruits, int r, int c) {
        if (r == N-1) {
            if (c == N-1) return 0;
            return INT_MIN;
        }
        if (c <= r) return 0;
        if (dp[r][c] != -1) return dp[r][c];

        int res = 0;
        if (c+1 < N) {
            res = max(res, fruits[r][c] + cal1(fruits, r+1, c+1));
        }
        if (c-1 >= 0) {
            res = max(res, fruits[r][c] + cal1(fruits, r+1, c-1));
        }
        res = max(res, fruits[r][c] + cal1(fruits, r+1, c));

        return dp[r][c] = res;
    }

    int cal2(vector<vector<int>>& fruits, int r, int c) {
        if (c == N-1) {
            if (r == N-1) return 0;
            return INT_MIN;
        }
        if (c >= r) return 0;
        if (dp[r][c] != -1) return dp[r][c];

        int res = 0;
        if (r+1 < N) {
            res = max(res, fruits[r][c] + cal2(fruits, r+1, c+1));
        }
        if (r-1 >= 0) {
            res = max(res, fruits[r][c] + cal2(fruits, r-1, c+1));
        }
        res = max(res, fruits[r][c] + cal2(fruits, r, c+1));

        return dp[r][c] = res;
    }

    int maxCollectedFruits(vector<vector<int>>& fruits) {
        // the child from (0, 0) will move to (1, 1), (2, 2), ... (n, n)
        // the child from (0, n-1) will not go to the grid where i==j
        // the child from (n-1, 0) will not go to the grid where i==j
        N = fruits.size();
        for (int i=0; i<N; i++) {
            tot += fruits[i][i];
        }
        memset(dp, -1, sizeof(dp));
        tot += cal1(fruits, 0, N-1);
        memset(dp, -1, sizeof(dp));
        tot += cal2(fruits, N-1, 0);

        return tot;
    }
};



// Same time complexity but more concise
// https://leetcode.cn/problems/find-the-maximum-number-of-fruits-collected/solutions/2998667/nao-jin-ji-zhuan-wan-wang-ge-tu-dppython-gjcm/
class Solution {
public:
    int N;
    int dfs(int r, int c, vector<vector<int>>& fruits, vector<vector<int>>& memo) {
        if (c < N-1-r || c >= N) {
            return INT_MIN;
        }
        if (r == 0) return fruits[r][c];  // when r == 0 and c == N-1

        if (memo[r][c] != -1) return memo[r][c];

        int res = fruits[r][c] + max({dfs(r-1, c, fruits, memo), dfs(r-1, c-1, fruits, memo), dfs(r-1, c+1, fruits, memo)});

        return memo[r][c] = res;
    }
    int maxCollectedFruits(vector<vector<int>>& fruits) {
        this->N = fruits.size();
        int res = 0;

        for (int i=0; i<N; i++) {
            res += fruits[i][i];
        }

        vector<vector<int>> memo(N, vector<int>(N, -1));

        res += dfs(N-2, N-1, fruits, memo);
        for (int i=0; i<N; i++) {
            for (int j=i+1; j<N; j++) {
                fruits[i][j] = fruits[j][i];
            }
        }

        ranges::fill(memo, vector(N, -1));
        res += dfs(N-2, N-1, fruits, memo);

        return res;
    }
};