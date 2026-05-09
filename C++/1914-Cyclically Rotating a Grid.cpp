class Solution {
public:
    vector<vector<int>> rotateGrid(vector<vector<int>>& grid, int k) {
        int row = grid.size(), col = grid[0].size();

        for (int rc=0; rc<(min(row, col))/2; rc++) {
            vector<int> arr;
            // upper row
            for (int c=rc; c<col-rc-1; c++) {
                arr.push_back(grid[rc][c]);
            }
            // right col
            for (int r=rc; r<row-rc-1; r++) {
                arr.push_back(grid[r][col-1-rc]);
            }
            // lower row
            for (int c=col-1-rc; c>rc; c--) {
                arr.push_back(grid[row-1-rc][c]);
            }
            // left col
            for (int r=row-1-rc; r>rc; r--) {
                arr.push_back(grid[r][rc]);
            }

            int tmpK = k%((int)arr.size());
            rotate(arr.begin(), arr.begin()+tmpK, arr.end());
            int idx = 0;
            for (int c=rc; c<col-rc-1; c++) {
                grid[rc][c] = arr[idx++];
            }
            // right col
            for (int r=rc; r<row-rc-1; r++) {
                grid[r][col-1-rc] = arr[idx++];
                // arr.push_back(grid[r][col-1-rc]);
            }
            // lower row
            for (int c=col-1-rc; c>rc; c--) {
                grid[row-1-rc][c] = arr[idx++];
                // arr.push_back(grid[row-1-rc][c]);
            }
            // left col
            for (int r=row-1-rc; r>rc; r--) {
                grid[r][rc] = arr[idx++];
                // arr.push_back(grid[r][rc]);
            }
        }

        
        return grid;
    }
};