using TSII = tuple<string, int, int>;
class Solution {
public:
    vector<int> d = {1, 0, -1, 0, 1};
    int slidingPuzzle(vector<vector<int>>& board) {
        int zeroIdx = -1;
        int row = board.size(), col = board[0].size();
        string state = "";
        for (int r=0; r<row; r++) {
            for (int c=0; c<col; c++) {
                if (board[r][c] == 0) zeroIdx = r*col+c;
                state += board[r][c] + '0';
            }
        }

        queue<TSII> q;
        q.push({state, zeroIdx, 0});
        unordered_set<string> visited;
        string goal = "123450";

        while (!q.empty()) {
            auto [state, zeroIdx, step] = q.front();
            q.pop();
            if (state == goal) return step;
            if (visited.contains(state)) continue;
            visited.insert(state);
            int currR = zeroIdx/col, currC = zeroIdx%col;
            for (int i=0; i<4; i++) {
                int nr = currR + d[i], nc = currC + d[i+1];
                if (0<=nr && nr<row && 0<=nc && nc<col) {
                    string newState = state;
                    swap(newState[zeroIdx], newState[nr*col+nc]);
                    if (!visited.contains(newState)) {
                        q.push({newState, nr*col+nc, step+1});
                    }
                }
            }
        }

        return -1;
    }
};