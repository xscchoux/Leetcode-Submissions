class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int row = mat.size(), col = mat[0].size();
        vector<int> rowCount(row, 0), colCount(col, 0);
        int res = 0;
        
        for (int r=0; r<row; r++){
            for (int c=0; c<col; c++){
                if (mat[r][c]==1){
                    rowCount[r]++;
                    colCount[c]++;
                }
            }
        }

        for (int r=0; r<row; r++){
            for (int c=0; c<col; c++){
                if (mat[r][c]==1 && rowCount[r] == 1 && colCount[c] == 1){
                    res++;
                }
            }
        }
        
        return res;
    }
};