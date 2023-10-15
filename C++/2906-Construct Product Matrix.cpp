class Solution {
public:
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        // prefix and suffix
        int product = 1;
        int kMod = 12345;
        int row = grid.size(), col = grid[0].size();
        vector<vector<int>> res = vector(row, vector(col, 0));
        
        for (int r = 0; r < row; r++){
            for (int c = 0; c < col; c++){
                res[r][c] = product;
                product = product*(grid[r][c]%kMod)%kMod;
            }
        }

        product = 1;
        for (int r = row-1; r >= 0; r--){
            for (int c = col-1; c >= 0; c--){
                res[r][c] = product*res[r][c]%kMod;
                product = product*(grid[r][c]%kMod)%kMod;
            }
        }
        
        return res;
    }
};