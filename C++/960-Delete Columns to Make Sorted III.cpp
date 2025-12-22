class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int row = strs.size(), col = strs[0].size(), maxLen = 1;

        vector<int> dp(col, 1);

        for (int c=1; c<col; c++) {
            for (int prevC=0; prevC<c; prevC++) {
                bool flag = true;
                for (int r=0; r<row; r++) {
                    if (strs[r][c] < strs[r][prevC]) {
                        flag = false;
                        break;
                    }
                }
                if (flag) {
                    dp[c] = max(dp[c], dp[prevC]+1);
                }
            }
            maxLen = max(maxLen, dp[c]);
        }

        return col-maxLen;
    }
};