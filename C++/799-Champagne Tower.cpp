class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        double dp[101][101] = {};
        dp[0][0] = poured;

        for (int r=0; r<=query_row; r++) {
            for (int c=0; c<=r; c++) {
                if (dp[r][c] > 1) {
                    double remain = (double)(dp[r][c]-1.0)/2.0;
                    dp[r][c] = 1.0;
                    dp[r+1][c] += remain;
                    dp[r+1][c+1] += remain;
                }
                if (r == query_row && c == query_glass) {
                    return dp[r][c];
                }

            }
        }

        return -1;
    }
};


// Better, space optimized
class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        double dp[101] = {};
        dp[0] = poured;

        for (int r=0; r<query_row; r++) {
            for (int c=r; c>=0; c--) {
                double tmp = dp[c];
                double remain = max(0.0, (tmp-1.0)/2.0);
                dp[c+1] += remain;
                dp[c] = remain;
            }
        }

        return min(dp[query_glass], 1.0);
    }
};