class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int row = mat.size(), col = mat[0].size();
        vector<int> mapping(row*col+1);
        vector<int> cntRow(row), cntCol(col);

        for (int r=0; r<row; r++) {
            for (int c=0; c<col; c++) {
                mapping[mat[r][c]] = r*col+c;
            }
        }

        for (int i=0; i<arr.size(); i++) {
            int coord = mapping[arr[i]];

            int currR = coord/col;
            int currC = coord%col;

            if (++cntRow[currR] == col || ++cntCol[currC] == row) {
                return i;
            }
        }         
        return 0;
    }
};