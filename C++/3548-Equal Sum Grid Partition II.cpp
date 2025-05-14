using LL = long long;
class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int row = grid.size(), col = grid[0].size();
        LL tot1 = 0, tot2 = 0;
        vector<int> cnt1(100001, 0), cnt2(100001, 0);  // count of values in region 1 and region 2 after a vertical cut

        for (int r=0; r<row; r++) {
            for (int c=0; c<col; c++) {
                cnt2[grid[r][c]]++;
                tot2 += grid[r][c];
            }
        }

        vector<int> cnt22 = cnt2, cnt11(100001, 0);   // count of values in region 1 and region 2 after a horizontal cut
        LL tot22 = tot2, tot11 = tot1;


        // vertical cut
        for (int c=0; c<col-1; c++) {
            for (int r=0; r<row; r++) {
                cnt1[grid[r][c]]++;
                cnt2[grid[r][c]]--;
                tot1 += grid[r][c];
                tot2 -= grid[r][c];
            }
            if (tot1 == tot2) {
                return true;
            }
            int diff = tot2 - tot1;
            if (abs(diff) > 1e5) continue;

            if (diff < 0) {
                if (c == 0) {
                    if (tot1 - grid[0][0] == tot2 || tot1 - grid[row-1][0] == tot2) {
                        return true;
                    }
                } else {
                    if (cnt1[-diff] > 0) {
                        if (row > 1) {
                            return true;
                        }
                        else if (grid[0][0] == -diff || grid[0][c] == -diff) {  // when row == 1, we have only two choices when discounting
                            return true;
                        }
                    }
                }
            } else { // diff > 0, tot2 > tot1
                if (c+1 == col-1 || row == 1) {
                    if (tot2 - grid[0][col-1] == tot1 || tot2 - grid[row-1][col-1] == tot1) return true;
                } else {
                    if (cnt2[diff] > 0) {
                        if (row > 1) {
                            return true;
                        }
                        else if (grid[0][c+1] == diff || grid[0][col-1] == diff) {  // when row == 1, we have only two choices when discounting
                            return true;
                        }
                    }
                }
            }
        }

        // horizontal cut
        for (int r=0; r<row-1; r++) {
            for (int c=0; c<col; c++) {
                cnt11[grid[r][c]]++;
                cnt22[grid[r][c]]--;
                tot11 += grid[r][c];
                tot22 -= grid[r][c];
            }
            if (tot11 == tot22) {
                return true;
            }
            LL diff = tot22 - tot11;
            if (abs(diff) > 1e5) continue;

            if (diff < 0) { // tot2 < tot1
                if (r == 0) {
                    if ((tot11 - grid[0][0] == tot22) || (tot11 - grid[0][col-1] == tot22)) {
                        return true;
                    }
                } else {
                    if (cnt11[-diff]) {
                        if (col > 1) {
                            return true;
                        }
                        else if (grid[0][0] == -diff || grid[r][0] == -diff) {  // when col == 1, we have only two choices when discounting
                            return true;
                        }
                    }
                }
            } else { // diff > 0, tot2 > tot1
                if (r+1 == row-1 || col == 1) {
                    if (tot22 - grid[row-1][0] == tot11 || tot22 - grid[row-1][col-1] == tot11) {
                        return true;
                    }
                } else {
                    if (cnt22[diff]) {
                        if (col > 1) {
                            return true;
                        }
                        else if (grid[r+1][0] == diff || grid[row-1][0] == diff) {  // when col == 1, we have only two choices when discounting
                            return true;
                        }
                    }
                }
            }
        }

        return false;
    }
};