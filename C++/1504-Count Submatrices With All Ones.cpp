// O(row*col)
class Solution {
public:
    int numSubmat(vector<vector<int>>& mat) {
        int row = mat.size(), col = mat[0].size(), res = 0;

        for (int r=0; r<row; r++) {
            stack<int> stk;   // keep a monotonically increasing stack
            vector<int> record(col, 0);
            for (int c=0; c<col; c++) {
                if (r > 0 && mat[r][c]) {
                    mat[r][c] += mat[r-1][c];
                }
                while (!stk.empty() && mat[r][c] <= mat[r][stk.top()]) {
                    stk.pop();
                }
                if (stk.empty()) {
                    record[c] += mat[r][c]*(c+1);
                    res += record[c];
                } else {
                    int dist = c - stk.top();
                    record[c] += mat[r][c]*dist;
                    record[c] += record[stk.top()];  // note the trick here
                    res += record[c];
                }
                stk.push(c);
            }
        }

        return res;
    }
};