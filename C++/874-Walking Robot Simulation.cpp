using PII = pair<int, int>;
class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        vector<PII> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}}; // Turn right 90 degrees as index increases
        int dirIdx = 0, x = 0, y = 0;
        unordered_set<int> obstacleSet;
        for (auto &obs:obstacles) {
            int x = obs[0], y = obs[1];
            obstacleSet.insert(x*(6e4) + y);  // use 6e4, not 3e4!!
        }

        int res = 0;
        for (int c:commands) {
            if (c == -1) {
                dirIdx = (dirIdx+1)%4;
            } else if (c == -2) {
                dirIdx = ((dirIdx-1)+4)%4;  // need to add 4 here!!
            } else {
                while (c-- > 0) {
                    int nxtX=x+directions[dirIdx].first, nxtY=y+directions[dirIdx].second;
                    int nxtXY = nxtX*(6e4)+nxtY;
                    if (!obstacleSet.contains(nxtXY)) {
                        x = nxtX;
                        y = nxtY;
                    } else {
                        break;
                    }
                }
                res = max(res, x*x+y*y);
            }
        }

        return res;
    }
};