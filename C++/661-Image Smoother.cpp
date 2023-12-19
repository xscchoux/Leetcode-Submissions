class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        int row = img.size(), col = img[0].size();
        vector<int> dr = {-1, 0, 1}, dc = {-1, 0, 1};
        vector<vector<int>> res(row, vector<int>(col));
        for (int r=0; r<row; r++){
            for (int c=0; c<col; c++){
                int count = 0, tot = 0;
                for (int delta_r:dr){
                    for (int delta_c:dc){
                        int nr = r+delta_r, nc = c+delta_c;
                        if (nr>=0 && nr < row && nc>=0 && nc < col){
                            count++;
                            tot += img[nr][nc];
                        }
                    }
                }
                res[r][c] = tot/count;
            }
        }
        return res;
    }
};