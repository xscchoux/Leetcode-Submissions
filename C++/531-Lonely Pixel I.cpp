class Solution {
public:
    int findLonelyPixel(vector<vector<char>>& picture) {
        int row = picture.size(), col = picture[0].size();
        vector<int> rowCnt(row, 0), colCnt(col, 0);

        for (int r=0; r<row; r++) {
            for (int c=0; c<col; c++) {
                if (picture[r][c] == 'B') {
                    rowCnt[r]++;
                    colCnt[c]++;
                }
            }
        }

        int res = 0;
        for (int r=0; r<row; r++) {
            for (int c=0; c<col; c++) {
                if (picture[r][c] == 'B' && rowCnt[r] == 1 && colCnt[c] == 1) {
                    res++;
                }
            }
        }

        return res;
    }
};