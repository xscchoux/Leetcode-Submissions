class Solution {
public:
    int minTotalDistance(vector<vector<int>>& grid) {
        vector<int> rowPos, colPos;
        int res = 0;
        for (int r=0; r<grid.size(); r++){
            for (int c=0; c<grid[0].size(); c++){
                if (grid[r][c] == 1){
                    rowPos.push_back(r);
                    colPos.push_back(c);
                }
            }
        }
        sort(colPos.begin(), colPos.end());
        for (int i=0; i<rowPos.size()/2; i++){
            res += rowPos[rowPos.size()-i-1] - rowPos[i];
        }
        
        for (int i=0; i<colPos.size()/2; i++){
            res += colPos[colPos.size()-i-1] - colPos[i];
        }
        
        return res;
    }
};