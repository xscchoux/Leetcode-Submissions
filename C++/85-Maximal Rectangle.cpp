class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int row = matrix.size(), col = matrix[0].size();
        vector<int> histogram(col, 0);
        int res = 0;

        for (int r=0; r<row; r++) {
            for (int c=0; c<col; c++) {
                if (matrix[r][c] == '1') {
                    histogram[c] += 1; 
                } else {
                    histogram[c] = 0;
                }
            }
            
            stack<int> stk;
            for (int c=0; c<col; c++) {
                while (!stk.empty() && histogram[c] <= histogram[stk.top()]) {
                    int h = histogram[stk.top()];
                    stk.pop();
                    int w = (stk.empty())?c:c-stk.top()-1;
                    res = max(res, w*h);
                }
                stk.push(c);
            }
            
            // the remaining monotonic increasing histogram
            while (!stk.empty()) {
                int h = histogram[stk.top()];
                stk.pop();
                int w = (stk.empty())?col:col-stk.top()-1;
                res = max(res, w*h);
            }
        }
        
        return res;
    }
};