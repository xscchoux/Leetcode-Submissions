// Just check Leetcode hints
class Solution {
public:
    vector<string> createGrid(int m, int n, int k) {
        if ((m == 1 || n == 1) && k > 1) {
            return {};
        }
        
        vector<string> grid(m, string(n, '#'));

        if (k == 1) {
            for (int c=0; c<n; c++) {
                grid[0][c] = '.';
            }
            for (int r=0; r<m; r++) {
                grid[r][n-1] = '.';
            }
        } else if (k == 2) {
            if (m < 2 || n < 2) return {};
            
            for (int r=0; r<2; r++) {
                for (int c=0; c<2; c++) {
                    grid[r][c] = '.';
                }
            }

            for (int c=2; c<n; c++) {
                grid[1][c] = '.';
            }
            for (int r=2; r<m; r++) {
                grid[r][n-1] = '.';
            }

        } else if (k == 3) {
            // 2x3 or 3x2
            if (m>=2 && n>=3) {
                for (int r=0; r<2; r++) {
                    for (int c=0; c<3; c++) {
                        grid[r][c] = '.';
                    }
                }
                for (int c=3; c<n; c++) {
                    grid[1][c] = '.';
                }
                for (int r=2; r<m; r++) {
                    grid[r][n-1] = '.';
                }
            } else if (m>=3 && n>=2) {
                for (int r=0; r<3; r++) {
                    for (int c=0; c<2; c++) {
                        grid[r][c] = '.';
                    }
                }
                for (int c=2; c<n; c++) {
                    grid[2][c] = '.';
                }
                for (int r=3; r<m; r++) {
                    grid[r][n-1] = '.';
                }                
            } else {
                return {};
            }
        } else { // k == 4
            // 2x4 or 4x2 or 3x3
            if (m >= 2 && n >= 4) {
                for (int r=0; r<2; r++) {
                    for (int c=0; c<4; c++) {
                        grid[r][c] = '.';
                    }
                }
                for (int c=4; c<n; c++) {
                    grid[1][c] = '.';
                }
                for (int r=2; r<m; r++) {
                    grid[r][n-1] = '.';
                }                   
            } else if (m >= 4 && n >= 2) {
                for (int r=0; r<4; r++) {
                    for (int c=0; c<2; c++) {
                        grid[r][c] = '.';
                    }
                }
                for (int c=2; c<n; c++) {
                    grid[3][c] = '.';
                }
                for (int r=4; r<m; r++) {
                    grid[r][n-1] = '.';
                }                    
            } else if (m >= 3 && n >= 3) {
                for (int r=0; r<3; r++) {
                    for (int c=0; c<3; c++) {
                        grid[r][c] = '.';
                    }
                }
                
                grid[0][2] = '#';
                grid[2][0] = '#';

                for (int c=3; c<n; c++) {
                    grid[2][c] = '.';
                }
                for (int r=3; r<m; r++) {
                    grid[r][n-1] = '.';
                }                        
            } else {
                return {};
            }
        }


        
        return grid;
    }
};