// O(mn), O(mn) space
class Solution {
public:
    int smallestCommonElement(vector<vector<int>>& mat) {
        int row = mat.size(), col = mat[0].size();
        map<int, int> hmap;
        for (int r=0; r<row; r++) {
            for (int c=0; c<col; c++) {
                hmap[mat[r][c]]++;
            }
        }

        for (auto &[k, v]:hmap) {
            if (v == row) {
                return k;
            }
        }

        return -1;
    }
};


// https://leetcode.com/problems/find-smallest-common-element-in-all-rows/editorial/
// Approach 3, O(mn), much faster, O(n) space
class Solution {
public:
    int smallestCommonElement(vector<vector<int>>& mat) {
        int row = mat.size(), col = mat[0].size(), cnt = 0, currMax = 0;
        vector<int> pos(row);

        while (true) {
            for (int r=0; r<row; r++) {
                while (pos[r] < col && currMax > mat[r][pos[r]]) {
                    pos[r]++;
                }
                if (pos[r] == col) return -1;
                if (mat[r][pos[r]] > currMax) {
                    currMax = mat[r][pos[r]];
                    cnt = 1;
                } else {
                    cnt++;
                }
                if (cnt == row) {
                    return currMax;
                }
            }
        }

        return -1;
    }
};