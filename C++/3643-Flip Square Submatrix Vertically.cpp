class Solution {
public:
    vector<vector<int>> reverseSubmatrix(vector<vector<int>>& grid, int x, int y, int k) {
        int start_row = x, end_row = x + k - 1;

        while (start_row < end_row) {
            swap_ranges(grid[start_row].begin() + y, grid[start_row].begin() + y + k, grid[end_row].begin() + y);
            start_row++;
            end_row--;
        }

        return grid;
    }
};