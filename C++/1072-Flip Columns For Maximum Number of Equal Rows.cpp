class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
        // count rows either x == y or x^y == 111111....
        // => store the count of (the value of matrix[r][i]^matrix[r][0] for i = 0...column width in each row) in an unordered_map
        const int bitLen = matrix[0].size();
        unordered_map<bitset<300>, int> cnt;

        for (auto &row:matrix) {
            int first = row[0];
            bitset<300> curr;
            for (int i=0; i<bitLen; i++) {
                curr[i] = first^row[i];
            }
            cnt[curr]++;
        }

        return max_element(cnt.begin(), cnt.end(), [](auto &a, auto &b) {
            return a.second < b.second;
        })->second;;
    }
};