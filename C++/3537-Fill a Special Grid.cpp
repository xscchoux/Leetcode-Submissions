class Solution {
public:
    int num = 0;
    void helper(int left, int top, int down, vector<vector<int>>& res) {
        if (top == down) {
            res[top][left] = num++;
            return;
        }

        helper(left + (down-top+1)/2, top, top + (down-top+1)/2 - 1, res);
        helper(left + (down-top+1)/2, top + (down-top+1)/2, down, res);
        helper(left, top + (down-top+1)/2, down, res);
        helper(left, top, top + (down-top+1)/2 - 1, res);      
    }
    vector<vector<int>> specialGrid(int n) {
        int full = pow(2, n);
        vector<vector<int>> res(full, vector<int>(full, 0));
        helper(0, 0, full-1, res);
        
        return res;
    }
};