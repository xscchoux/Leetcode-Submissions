class Solution {
public:
    int findChampion(vector<vector<int>>& grid) {
        int N = grid.size();
        int strongest = -1;
        for (int r=0; r<N; r++){
            for (int c=0; c<N; c++){
                if (grid[r][c] == 1){
                    if (strongest == -1 || c == strongest) strongest = r;
                }
            }
        }
        return strongest;
    }
};