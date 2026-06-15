class Solution {
public:
    long long maxRatings(vector<vector<int>>& units) {
        int row = units.size(), col = units[0].size();

        // edge case
        if (col == 1) {
            long long tot = 0;
            for (int r=0; r<row; r++) {
                tot += units[r][0];
            }
            return tot;
        }

        // sort all unit
        for (auto &unit:units) {
            sort(begin(unit), end(unit));
        }

        // find the global minimum mn
        int mn = INT_MAX;
        for (int r=0; r<row; r++) {
            mn = min(mn, units[r][0]);
        }

        // The key to to move the global minimum to the correct row
        // For other rows, move the minimum number the the row with global minimum
        
        long long tot = 0, toRemove = 0;
        int diff = INT_MAX;
        for (auto &unit:units) {
            tot += unit[1];
            if (unit[1] - mn < diff) {
                diff = unit[1] - mn;
                toRemove = unit[1];
            }
        }
        return tot + mn - toRemove;
    }
};