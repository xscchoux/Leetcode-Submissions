class Solution {
public:
    vector<int> z_array(string& s) {
        int N = s.size();
        vector<int> Z(N, 0);
        int l = 0, r = 0;
        for (int i=1; i<N; i++) {
            if (i>r) {
                l = r = i;
                while (r<N && s[r] == s[r-l]) {
                    r++;
                }
                Z[i] = r-l;
                r--;
            } else {
                int k = i-l;
                if (i + Z[k] <= r) {
                    Z[i] = Z[k];
                } else {
                    l = i;
                    while (r<N && s[r] == s[r-l]) {
                        r++;
                    }
                    Z[i] = r-l;
                    r--;                    
                }
            }
        }
        return Z;
    }
    int countCells(vector<vector<char>>& grid, string pattern) {
        int row = grid.size(), col = grid[0].size(), Np = pattern.size();
        string vertical = pattern + '#', horizontal = pattern + '#';

        for (int r=0; r<row; r++) {
            for (int c=0; c<col; c++) {
                horizontal += grid[r][c];
            }
        }

        for (int c=0; c<col; c++) {
            for (int r=0; r<row; r++) {
                vertical += grid[r][c];
            }
        }

        vector<int> verticalZ = z_array(vertical);
        vector<int> horizontalZ = z_array(horizontal);

        vector<vector<bool>> fillVertical(row, vector<bool>(col, false));
        vector<vector<bool>> fillHorizontal(row, vector<bool>(col, false));

        int end = -1;
        for (int i=Np+1; i<verticalZ.size(); i++) {
            if (verticalZ[i] == Np) {
                end = max(end, i+Np-1);
            }
            if (end >= i) {
                int rowIdx = (i-Np-1)%row, colIdx = (i-Np-1)/row;
                fillVertical[rowIdx][colIdx] = true;
            }
        }

        end = -1;
        for (int i=Np+1; i<horizontalZ.size(); i++) {
            if (horizontalZ[i] == Np) {
                end = max(end, i+Np-1);
            }
            if (end >= i) {
                int colIdx = (i-Np-1)%col, rowIdx = (i-Np-1)/col;
                fillHorizontal[rowIdx][colIdx] = true;
            }
        }

        int res = 0;
        for (int r=0; r<row; r++) {
            for (int c=0; c<col; c++) {
                if (fillHorizontal[r][c] && fillVertical[r][c]) {
                    res++;
                }
            }
        }

        return res;
    }
};