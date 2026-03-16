// O((mn)^2)
class Solution {
public:
    int row, col;
    bool isOK(int r, int c, int side) {
        if (c-side >= 0 && c+side < col && r + 2*side < row) {
            return true;
        }
        return false;
    }
    vector<int> getBiggestThree(vector<vector<int>>& grid) {
        set<int> numSet;

        this->row = grid.size();
        this->col = grid[0].size();

        for (int r=0; r<row; r++) {
            for (int c=0; c<col; c++) {
                numSet.insert(grid[r][c]);
                if (numSet.size() > 3) {
                    numSet.erase(numSet.begin());
                }

                int side = 1;
                while (isOK(r, c, side)) {
                    int tot = 0;
                    // upper right
                    int tmpR = r, tmpC = c, tmpSide = 0;
                    do {
                        tot += grid[tmpR][tmpC];
                        tmpR++;
                        tmpC++;
                        tmpSide++;
                    } while (tmpSide < side);

                    // lower right
                    tmpSide = 0;
                    do {
                        tot += grid[tmpR][tmpC];
                        tmpR++;
                        tmpC--;
                        tmpSide++;
                    } while (tmpSide < side);

                    // lower left
                    tmpSide = 0;
                    do {
                        tot += grid[tmpR][tmpC];
                        tmpR--;
                        tmpC--;
                        tmpSide++;
                    } while (tmpSide < side);

                    // upper left
                    tmpSide = 0;
                    do {
                        tot += grid[tmpR][tmpC];
                        tmpR--;
                        tmpC++;
                        tmpSide++;
                    } while (tmpSide < side);

                    side++;
                    numSet.insert(tot);
                    if (numSet.size() > 3) {
                        numSet.erase(numSet.begin());
                    }
                }
            }
        }
        
        vector<int> res;
        for (auto it = numSet.begin(); it != numSet.end(); it++) {
            res.push_back(*it);
        }

        reverse(begin(res), end(res));
        
        return res;
    }
};