class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int row = matrix.size(), col = matrix[0].size();
        vector<vector<int>> preSums;
        int res = 0;
        for (int r=0; r<row; r++) {
            vector<int> tmp = {0};
            for (int c=0; c<col; c++) {
                tmp.push_back(tmp[tmp.size()-1] + matrix[r][c]);
            }
            preSums.push_back(tmp);
        }
        
        for (int startCol = 0; startCol < col; startCol++) {
            for (int endCol = startCol; endCol < col; endCol++) {
                unordered_map<int, int> hmap;
                hmap[0] = 1;
                int acc = 0;
                for (int r=0; r<row; r++) {
                    acc += preSums[r][endCol+1] - preSums[r][startCol];
                    if (hmap.find(acc-target) != hmap.end()) {
                        res += hmap[acc-target];
                    }
                    hmap[acc]++;
                }
            }
        }
        return res;
    }
};