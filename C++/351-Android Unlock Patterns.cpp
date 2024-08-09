// O(9*8!)
class Solution {
public:
    int cal(int start, int least, int most, int forbidden[10][10]) {
        vector<pair<int, int>> path;
        path.push_back({0^(1<<start), start});
        int currNum = 1, res = 0;

        while (true) {  // At most visits grids 8! times
            if (currNum >= least) res += path.size();
            if (currNum == most) break;
            
            vector<pair<int, int>> nxtPath;
            for (auto &[bitMap, curr]:path) {
                for (int nxt=1; nxt<=9; nxt++) {    // O(9)
                    if ((bitMap&(1<<nxt)) != 0) continue;
                    if (forbidden[curr][nxt] != 0 && (bitMap&(1<<forbidden[curr][nxt])) == 0) {
                        continue;
                    }
                    nxtPath.push_back({bitMap^(1<<nxt), nxt});
                }
            }
            path = nxtPath;
            currNum++;
        }
        return res;
    }
    int numberOfPatterns(int m, int n) {
        int forbidden[10][10] = {0};
        forbidden[1][3] = 2; forbidden[3][1] = 2;
        forbidden[4][6] = 5; forbidden[6][4] = 5;
        forbidden[7][9] = 8; forbidden[9][7] = 8;
        forbidden[1][7] = 4; forbidden[7][1] = 4;
        forbidden[2][8] = 5; forbidden[8][2] = 5;
        forbidden[3][9] = 6; forbidden[9][3] = 6;
        forbidden[1][9] = 5; forbidden[9][1] = 5;
        forbidden[3][7] = 5; forbidden[7][3] = 5;

        int res = 4*cal(1, m, n, forbidden) + 4*cal(2, m, n, forbidden) + cal(5, m, n, forbidden);

        return res;
    }
};