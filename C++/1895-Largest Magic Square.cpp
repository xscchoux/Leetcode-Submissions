class Solution {
public:
    bool isOK(vector<vector<int>>& grid, int side) {
        int row = grid.size(), col = grid[0].size();
        
        for (int r=0; r+side<=row; r++) {
            for (int c=0; c+side<=col; c++) {
                int sum = accumulate(grid[r].begin()+c, grid[r].begin()+c+side, 0);
                bool equal = true;

                for (int currR = r+1; currR<r+side; currR++) {
                    int tot = 0;
                    for (int currC=c; currC<c+side; currC++) {
                        tot += grid[currR][currC];
                    }
                    if (sum != tot) {
                        equal = false;
                        break;
                    }
                }
                
                if (!equal) continue;

                for (int currC = c; currC<c+side; currC++) {
                    int tot = 0;
                    for (int currR=r; currR<r+side; currR++) {
                        tot += grid[currR][currC];
                    }
                    if (sum != tot) {
                        equal = false;
                        break;
                    }
                }

                if (!equal) continue;

                int diagonal = 0, antiDiagonal = 0;
                for (int toAdd=0; toAdd<side; toAdd++) {
                    diagonal += grid[r+toAdd][c+toAdd];
                    antiDiagonal += grid[r+toAdd][c+side-1-toAdd];
                }
                
                if (diagonal != sum || antiDiagonal != sum) continue;

                return true;
            }
        }
        return false;

    }
    int largestMagicSquare(vector<vector<int>>& grid) {
        int mx = max(grid.size(), grid[0].size());

        for (int side=mx; side>=1; side--) {
            if (isOK(grid, side)) {
                return side;
            }
        }

        return 1;
    }
};