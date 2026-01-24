// O(mn*log(mn)), note that heap size is O(mn)
class Solution {
public:
    unordered_map<char, pair<int, int>> directions = {{'d',{1, 0}}, {'l',{0, -1}}, {'r',{0, 1}}, {'u',{-1, 0}}};
    string findShortestWay(vector<vector<int>>& maze, vector<int>& ball, vector<int>& hole) {
        int row = maze.size(), col = maze[0].size();
        priority_queue<tuple<int, string, int ,int, int, int>, vector<tuple<int, string, int ,int, int, int>>, greater<>> pq;

        pq.push({0, "", ball[0], ball[1], -1, -1});
        vector<vector<bool>> visited(row, vector<bool>(col, false));

        bool found = false;
        while (!pq.empty()) {
            auto [dist, path, r, c, prevR, prevC] = pq.top();
            pq.pop();

            if (visited[r][c]) continue;
            visited[r][c] = true;

            if (r == hole[0] && c == hole[1]) {
                return path;
            }

            for (auto [direction, movePair]:directions) {
                int nxtR = r, nxtC = c;
                int rMove = movePair.first, cMove = movePair.second;

                while (nxtR >= 0 && nxtR < row && nxtC >= 0 && nxtC < col && !(nxtR == hole[0] && nxtC == hole[1]) && maze[nxtR][nxtC] == 0) {
                    nxtR += rMove;
                    nxtC += cMove;
                }

                if (!(nxtR == hole[0] && nxtC == hole[1])) {
                    nxtR -= rMove;
                    nxtC -= cMove;
                }
                
                if (visited[nxtR][nxtC]) continue;
                int moved = abs(nxtR-r) + abs(nxtC-c);
                string newPath = path + direction;
                pq.push({dist+moved, newPath, nxtR, nxtC, r, c});
            }
        }

        return "impossible";
    }
};