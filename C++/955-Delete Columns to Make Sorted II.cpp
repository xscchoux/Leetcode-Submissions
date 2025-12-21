// https://www.cnblogs.com/grandyang/p/13453169.html
class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int col = strs[0].size(), row = strs.size();
        int res = 0;
        vector<bool> nxtGreater(row, false);

        for (int c=0; c<col; c++) {
            bool found = false;
            for (int r=0; r<row-1; r++) {
                if (!nxtGreater[r] && strs[r][c] > strs[r+1][c]) {
                    found = true;
                    res++;
                    break;
                }
            }
            if (found) continue;
            for (int r=0; r<row-1; r++) {
                nxtGreater[r] = nxtGreater[r] || (strs[r][c] < strs[r+1][c]);  // Don't write nxtGreater[r] |= (strs[r][c] < strs[r+1][c]); Cannot use | for vector<bool>  <- memorize this  
            }
        }
        return res;
    }
};