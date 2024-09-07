using LL = long long;
class Solution {
public:
    long long maximumValueSum(vector<vector<int>>& board) {
        int row = board.size(), col = board[0].size();
        vector<vector<int>> candidate;
        
        for (int r=0; r<row; r++) {
            vector<vector<int>> temp;
            for (int c=0; c<col; c++) {
                temp.push_back({board[r][c], r, c});
            }
            sort(temp.rbegin(), temp.rend());
            candidate.push_back(temp[0]);
            if (col>1) candidate.push_back(temp[1]);
            if (col>2) candidate.push_back(temp[2]);
        }

        LL ans = LLONG_MIN;

        for (int i=0; i<candidate.size()-2; i++) {
            LL fVal = candidate[i][0];
            int fR = candidate[i][1];
            int fC = candidate[i][2];
            for (int j=i+1; j<candidate.size()-1; j++) {
                LL sVal = candidate[j][0];
                int sR = candidate[j][1];
                int sC = candidate[j][2];
                if (fR == sR || fC == sC) continue;
                for (int k=j+1; k<candidate.size(); k++) {
                    LL tVal = candidate[k][0];
                    int tR = candidate[k][1];
                    int tC = candidate[k][2];
                    if (sR != tR && fR != tR && sC != tC && fC != tC) {
                        ans = max(ans, fVal+sVal+tVal);
                    }
                }
            }
        }

        return ans;
    }
};