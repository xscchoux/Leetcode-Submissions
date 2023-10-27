class Solution {
public:
    int numberOfWays(int n, int m, int k, vector<int>& source, vector<int>& dest) {
        // Partition grids into 4 groups: center, sameRow, sameCol, other
        // Each number corresponds the ways to reach one of the points in this group
        // All grids in the same group have the same number of ways to reach
        // Extremely hard!
        
        long center = 1;
        long sameRow = 0;
        long sameCol = 0;
        long other = 0;
        int kMod = 1e9 + 7;
        while (k > 0){
            long prevCenter = center;
            long prevSameRow = sameRow;
            long prevSameCol = sameCol;
            long prevOther = other;
            center = (prevSameRow*(m-1) + prevSameCol*(n-1))%kMod;
            sameRow = (prevCenter + prevSameRow*((m-2) > 0?(m-2):0) + prevOther*(n-1))%kMod;
            sameCol = (prevCenter + prevSameCol*((n-2) > 0?(n-2):0) + prevOther*(m-1))%kMod;
            other = (prevSameRow + prevSameCol + prevOther*((m-2) > 0?(m-2):0) + prevOther*((n-2) > 0?(n-2):0))%kMod;
            k--;
        }
        if (dest[0] == source[0] && dest[1] == source[1]){
            return center;
        } else if (dest[0] == source[0]){
            return sameRow;
        } else if (dest[1] == source[1]){
            return sameCol;
        } else{
            return other;
        }
    }
};