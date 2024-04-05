// O(row*col*3^L)
class Solution {
public:
    Solution() {
        dirs = {{0, -1}, {-1, 0}, {0, 1}, {1, 0}};
    }
    int N, row, col;
    bool visited[10][10];
    bool dfs(int r, int c, int wordIdx, vector<vector<char>>& board, string& word) {
        if (word[wordIdx] != board[r][c]) return false;
        if (word[wordIdx] == board[r][c] && wordIdx == N-1) return true;
        visited[r][c] = true;
        for (const auto& [dr, dc]:dirs) {
            int nr = r+dr, nc = c+dc;
            if (0<=nr && nr<row && 0<=nc && nc<col && !visited[nr][nc]) {
                if (dfs(r+dr, c+dc, wordIdx+1, board, word)) {
                    return true;
                }
            }
        }
        visited[r][c] = false;
        return false;
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        this->row = board.size();
        this->col = board[0].size();
        this->N = word.size();

        for (int r=0; r<row; r++) {
            for (int c=0; c<col; c++) {
                if (dfs(r, c, 0, board, word)) return true;
            }
        }
        
        return false;
    }
private:
    vector<pair<int, int>> dirs;
};