class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int col = strs[0].size(), row = strs.size();
        int res = 0;
        for (int c=0; c<col; c++) {
            for (int r=1; r<row; r++) {
                if (strs[r][c] < strs[r-1][c]) {
                    res++;
                    break;
                }
            }
        }

        return res;
    }
};