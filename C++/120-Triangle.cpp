class Solution {
public:
    int row;

    int dfs(int idx, int r, vector<vector<int>>& triangle, vector<vector<int>>& memo) {
        if (r == row) {
            return 0;
        }
        if (memo[idx][r] != INT_MAX) return memo[idx][r];
        int res = triangle[r][idx];
        res += min( dfs(idx, r+1, triangle, memo), dfs(idx+1, r+1, triangle, memo)); 

        return memo[idx][r] = res;
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        this->row = triangle.size();
        vector<vector<int>> memo(row, vector<int>(row, INT_MAX));
        
        return dfs(0, 0, triangle, memo);
    }
};