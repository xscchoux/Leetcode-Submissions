class Solution {
public:
    int row, col;
    bool isEnd(int r, int c, vector<vector<char>>& grid) {
        if (r < 0 || r >= row || c < 0 || c >= col || grid[r][c] == 'X') return true;
        return false;
    }
    vector<int> lastVisitedCell(vector<vector<char>>& grid) {
        this->row = grid.size();
        this->col = grid[0].size();

        queue<pair<int, int>> q;
        q.push({0, 0});

        while (!q.empty()) {
            auto [currR, currC] = q.front();
            q.pop();
            if (grid[currR][currC] == 'R') {
                if (isEnd(currR, currC+1, grid)) return {currR, currC};
                q.push({currR, currC+1});
                grid[currR][currC] = 'X';
            } else if (grid[currR][currC] == 'L') {
                if (isEnd(currR, currC-1, grid)) return {currR, currC};
                q.push({currR, currC-1});
                grid[currR][currC] = 'X';
            } else if (grid[currR][currC] == 'U') {
                if (isEnd(currR-1, currC, grid)) return {currR, currC};
                q.push({currR-1, currC});
                grid[currR][currC] = 'X';
            } else {
                if (isEnd(currR+1, currC, grid)) return {currR, currC};
                q.push({currR+1, currC});
                grid[currR][currC] = 'X';
            }
        }

        return {0, 0};
    }
};