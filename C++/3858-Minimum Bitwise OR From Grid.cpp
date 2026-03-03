// log2(100000) = 16.60964047...
// https://leetcode.com/problems/minimum-bitwise-or-from-grid/solutions/7616249/super-easy-full-clear-explanation-beginn-ylis/
class Solution {
public:
    int minimumOR(vector<vector<int>>& grid) {
        if (grid.size() == 1) {
            return *min_element(begin(grid[0]), end(grid[0]));
        }

        int row = grid.size(), col = grid[0].size();

        int zeroMask = 0; // giving positions that can be zero

        for (int bit = 16; bit >= 0; bit--) {
            int testMask = zeroMask | (1<<bit);
            bool can_be_zero = true;
            for (auto &row:grid) {
                bool found = false;
                for (int num:row) {
                    if ((num & testMask) == 0) {
                        found = true;
                        continue;
                    } 
                }
                if (!found) {
                    can_be_zero = false;
                    break;
                }
            }
            if (can_be_zero) {
                zeroMask = testMask;
            }
        }

        int res = (1<<17)-1;

        return res^zeroMask;
    }
};