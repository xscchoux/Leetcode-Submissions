struct TrieNode {
    TrieNode* children[26];
    string s = "";
    explicit TrieNode(){
        std::fill(children, children +26 , nullptr);
    }
    virtual ~TrieNode(){ // this makes code even faster
        for(TrieNode* e : children) delete e;
    }
};

class Solution {
public:
    int row, col;
    vector<string> res;
    vector<pair<int, int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        this->row = board.size();
        this->col = board[0].size();
        TrieNode* root = new TrieNode();
        for (string word:words) {
            TrieNode* node = root;
            for (char w:word) {
                if (node->children[w-'a'] == nullptr) {
                    node->children[w-'a'] = new TrieNode();
                }
                node = node->children[w-'a'];
            }
            node->s = word;
        }

        for (int r=0; r<row; r++) {
            for (int c=0; c<col; c++) {
                if (root->children[board[r][c]-'a'] == nullptr) continue;
                vector<vector<bool>> visited(row, vector<bool>(col, false));
                visited[r][c] = true;
                dfs(root->children[board[r][c]-'a'], r, c, board, visited);
            }
        }

        return res;
    }
    void dfs(TrieNode* node, int r, int c, vector<vector<char>>& board, vector<vector<bool>>& visited) {
        if (!((node->s).empty())) {
            res.push_back(node->s);
            node->s = "";     // note the trick here
        }
        for (auto &[dr, dc]:directions) {
            int nr = r+dr, nc = c+dc;
            if (0<=nr && nr<row && 0<=nc && nc<col && !visited[nr][nc] && node->children[board[nr][nc]-'a'] != nullptr) {
                visited[nr][nc] = true;
                dfs(node->children[board[nr][nc]-'a'], nr, nc, board, visited);
                visited[nr][nc] = false;
            }
        }
    }
};



// Better, without using vector<vector<bool>> visited
struct TrieNode {
    TrieNode* children[26];
    string s = "";
    explicit TrieNode(){
        std::fill(children, children +26 , nullptr);
    }
    virtual ~TrieNode(){ // this makes code even faster
        for(TrieNode* e : children) delete e;
    }
};

class Solution {
public:
    int row, col;
    vector<string> res;
    vector<pair<int, int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        this->row = board.size();
        this->col = board[0].size();
        TrieNode* root = new TrieNode();
        for (string word:words) {
            TrieNode* node = root;
            for (char w:word) {
                if (node->children[w-'a'] == nullptr) {
                    node->children[w-'a'] = new TrieNode();
                }
                node = node->children[w-'a'];
            }
            node->s = word;
        }

        for (int r=0; r<row; r++) {
            for (int c=0; c<col; c++) {
                if (root->children[board[r][c]-'a'] == nullptr) continue;
                dfs(root->children[board[r][c]-'a'], r, c, board);
            }
        }

        return res;
    }
    void dfs(TrieNode* node, int r, int c, vector<vector<char>>& board) {
        if (!((node->s).empty())) {
            res.push_back(node->s);
            node->s = "";     // note the trick here
        }
        char tmp = board[r][c];
        board[r][c] = '#';
        for (auto &[dr, dc]:directions) {
            int nr = r+dr, nc = c+dc;
            if (0<=nr && nr<row && 0<=nc && nc<col && board[nr][nc] != '#' && node->children[board[nr][nc]-'a'] != nullptr) {
                dfs(node->children[board[nr][nc]-'a'], nr, nc, board);
            }
        }
        board[r][c] = tmp;
    }
};