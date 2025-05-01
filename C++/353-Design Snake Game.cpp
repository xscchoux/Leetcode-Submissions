class SnakeGame {
public:
    int score = 0, r = 0, c = 0, width, height, foodIdx = 0;
    vector<vector<int>> food;
    unordered_map<string, pair<int, int>> dirMap;
    deque<pair<int, int>> dq;
    vector<vector<bool>> visited;

    SnakeGame(int width, int height, vector<vector<int>>& food) {
        this->food = food;
        this->width = width;
        this->height = height;
        dirMap["R"] = {0, 1};
        dirMap["D"] = {1, 0};
        dirMap["U"] = {-1, 0};
        dirMap["L"] = {0, -1};
        dq.push_back({0, 0});
        visited.resize(height, vector<bool>(width, false));
        visited[0][0] = true;
    }
    
    int move(string direction) {
        auto &[dr, dc] = dirMap[direction];
        int nr = r+dr, nc = c+dc;
        // out of boundary
        if (nr < 0 || nr >= height || nc < 0 || nc >= width) return -1;
        r = nr;
        c = nc;

        if (foodIdx < food.size() && nr == food[foodIdx][0] && nc == food[foodIdx][1]) {
            if (visited[nr][nc]) return -1;
            dq.push_back({nr, nc});
            visited[nr][nc] = true;

            score += 1;
            foodIdx++;
            return score;
        } else {
            // remove the tail position
            auto &[preR, preC] = dq.front();
            visited[preR][preC] = false;
            dq.pop_front();

            // extend
            if (visited[nr][nc]) return -1;
            dq.push_back({nr, nc});
            visited[nr][nc] = true;
            
            return score;
        }
    }
};

/**
 * Your SnakeGame object will be instantiated and called as such:
 * SnakeGame* obj = new SnakeGame(width, height, food);
 * int param_1 = obj->move(direction);
 */