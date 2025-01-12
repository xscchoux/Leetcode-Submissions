class Solution {
public:
    int maximumAmount(vector<vector<int>>& coins) {
        int row = coins.size(), col = coins[0].size();
        vector<vector<vector<int>>> dp(row, vector<vector<int>>(col, vector<int>(3, INT_MIN)));

        for (int r=0; r<row; r++) {
            for (int c=0; c<col; c++) {
                if (r==0 && c==0) {
                    if (coins[r][c] < 0) dp[r][c][1] = 0;
                    dp[r][c][0] = coins[r][c];
                } else {
                    for (int k=0; k<=2; k++) {
                        if (r > 0 && dp[r-1][c][k] > INT_MIN) {
                            if (k < 2 && coins[r][c] < 0) dp[r][c][k+1] = max(dp[r][c][k+1], dp[r-1][c][k]);
                            dp[r][c][k] = max(dp[r][c][k], dp[r-1][c][k]+coins[r][c]);
                        } 
                        if (c > 0 && dp[r][c-1][k] > INT_MIN) {
                            if (k < 2 && coins[r][c] < 0) dp[r][c][k+1] = max(dp[r][c][k+1], dp[r][c-1][k]);
                            dp[r][c][k] = max(dp[r][c][k], dp[r][c-1][k]+coins[r][c]);
                        } 
                    }   
                }
            }
        }

        return *max_element(begin(dp[row-1][col-1]), end(dp[row-1][col-1]));
    }
};