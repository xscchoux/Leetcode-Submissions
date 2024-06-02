class Solution {
private:
    vector<int> getCommon(vector<int>& a, vector<int>& b) {
        vector<int> res;
        int i1 = 0, i2 = 0;
        while (i1 < a.size() && i2 < b.size()) {
            if (a[i1] == b[i2]) {
                res.push_back(a[i1]);
                i1++; i2++;
            } else if (a[i1] < b[i2]) {
                i1++;
            } else {
                i2++;
            }
        }
        return res;
    }
public:
    vector<int> longestCommonSubsequence(vector<vector<int>>& arrays) {
        vector<int> common = arrays[0];
        for (int i=1; i<arrays.size(); i++) {
            if (common.empty()) return {};
            common = getCommon(common, arrays[i]);
        }

        return common;
    }
};