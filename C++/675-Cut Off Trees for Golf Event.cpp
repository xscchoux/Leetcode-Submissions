// O(m*n*m*n)
using TII = tuple<int, int, int>;
class Solution {
public:
    vector<pair<int, int>> directions = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    int cutOffTree(vector<vector<int>>& forest) {
        if (forest[0][0] == 0) return -1;
        int row = forest.size(), col = forest[0].size();
        vector<vector<int>> trees;


        for (int r=0; r<row; r++) {
            for (int c=0; c<col; c++) {
                if (forest[r][c] > 1) {
                    trees.push_back({forest[r][c], r, c});
                }
            }
        }

        sort(begin(trees), end(trees));
        trees.insert(trees.begin(), {forest[0][0], 0, 0});
        int res = 0;

        for (int i=1; i<trees.size(); i++) {
            int prevR = trees[i-1][1], prevC = trees[i-1][2];
            int currR = trees[i][1], currC = trees[i][2];
            int val = BFS(prevR, prevC, currR, currC, forest, row, col);
            if (val == -1) return -1;
            res += val;
        }

        return res;
    }

    int BFS(int prevR, int prevC, int currR, int currC, vector<vector<int>>& forest, int row, int col) {
        int res = 0, step = 0;
        queue<TII> q;
        q.push({prevR, prevC, 0});
        vector<vector<bool>> visited(row, vector<bool>(col, false));
        visited[prevR][prevC] = true;

        while (!q.empty()) {
            int length = q.size();
            while (length--) {
                auto [R, C, step] = q.front();
                q.pop();
                if (R == currR && C == currC) return step;
                for (auto &[dr, dc]:directions) {
                    int nxtR = R+dr, nxtC = C+dc;
                    if (0<=nxtR && nxtR<row && 0<=nxtC && nxtC<col && !visited[nxtR][nxtC] && forest[nxtR][nxtC] != 0) {
                        visited[nxtR][nxtC] = true;
                        q.push({nxtR, nxtC, step+1});
                    }
                }
            }
        }
        return -1;
    }

};