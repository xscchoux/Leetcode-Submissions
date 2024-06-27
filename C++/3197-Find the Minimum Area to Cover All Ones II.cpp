class Solution {
public:
    int process(vector<vector<int>>& grid, int r1, int c1, int r2, int c2) {
        int left = INT_MAX, right = INT_MIN, up = INT_MAX, down = INT_MIN;
        for (int r=r1; r<=r2; r++) {
            for (int c=c1; c<=c2; c++) {
                if (grid[r][c] == 1) {
                    left = min(left, c);
                    right = max(right, c);
                    up = min(up, r);
                    down = max(down, r);
                }
            }
        }
        if (left<=right && up<=down) return (right-left+1)*(down-up+1);
        return INT_MAX/3;
    }

    int minimumSum(vector<vector<int>>& grid) {
        int row = grid.size(), col = grid[0].size();
        int res = INT_MAX;

        /*
        -------------
        |    (1)    |
        -------------
        |    (2)    |
        -------------
        |    (3)    |
        -------------
        */

        for (int r1=0; r1+2<row; r1++) {
            for (int r2=r1+1; r2+1<row; r2++) {
                int area1 = process(grid, 0, 0, r1, col-1);
                int area2 = process(grid, r1+1, 0, r2, col-1);
                int area3 = process(grid, r2+1, 0, row-1, col-1);
                res = min(res, area1+area2+area3);
            }
        }

        /*
        -------------
        |   |   |   |
        |   |   |   |
        |(1)|(2)|(3)|
        |   |   |   |
        |   |   |   |
        -------------
        */

        for (int c1=0; c1+2<col; c1++) {
            for (int c2=c1+1; c2+1<col; c2++) {
                int area1 = process(grid, 0, 0, row-1, c1);
                int area2 = process(grid, 0, c1+1, row-1, c2);
                int area3 = process(grid, 0, c2+1, row-1, col-1);
                res = min(res, area1+area2+area3);
            }
        }

        /*
        -------------
        | (1) | (2) |
        |     |     |
        ------------
        |           |
        |    (3)    |
        -------------
        */

        for (int c=0; c+1<col; c++) {
            for (int r=1; r<row; r++) {
                int area1 = process(grid, 0, 0, r-1, c);
                int area2 = process(grid, 0, c+1, r-1, col-1);
                int area3 = process(grid, r, 0, row-1, col-1);
                res = min(res, area1+area2+area3);
            }
        }

        /*
        -------------
        |    (1)    |
        |           |
        -------------
        | (2) | (3) |
        |     |     |
        -------------
        */

        for (int r=0; r+1<row; r++) {
            for (int c=0; c+1<col; c++) {
                int area1 = process(grid, 0, 0, r, col-1);
                int area2 = process(grid, r+1, 0, row-1, c);
                int area3 = process(grid, r+1, c+1, row-1, col-1);
                res = min(res, area1+area2+area3);
            }
        }

        /*
        -------------
        |     | (2) |
        |     |     |
          (1) -------
        |     |     |
        |     | (3) |
        -------------
        */

        for (int c=0; c+1<col; c++) {
            for (int r=0; r+1<row; r++) {
                int area1 = process(grid, 0, 0, row-1, c);
                int area2 = process(grid, 0, c+1, r, col-1);
                int area3 = process(grid, r+1, c+1, row-1, col-1);
                res = min(res, area1+area2+area3);
            }
        }

        /*
        -------------
        |     |     |
        | (1) |     |
        ------- (3) |
        |     |     |
        | (2) |     |
        -------------
        */

        for (int r=0; r+1<row; r++) {
            for (int c=0; c+1<col; c++) {
                int area1 = process(grid, 0, 0, r, c);
                int area2 = process(grid, r+1, 0, row-1, c);
                int area3 = process(grid, 0, c+1, row-1, col-1);
                res = min(res, area1+area2+area3);
            }
        }

        return res;
    }
};