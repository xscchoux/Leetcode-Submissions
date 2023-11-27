class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        int row = matrix.size(), col = matrix[0].size();
        int res = 0;
        
        for (int r=0; r<row; r++){
            if (r > 0){
                for (int c=0; c<col; c++){
                    if (matrix[r][c] != 0) matrix[r][c] = matrix[r-1][c] + 1;
                }                
            }
            vector<int> tmp = matrix[r];
            sort(tmp.begin(), tmp.end(), greater<int>());

            for (int c=0; c<col; c++){
                res = max(res, tmp[c]*(c+1));
            }
        }
        return res;
    }
};