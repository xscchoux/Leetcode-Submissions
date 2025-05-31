class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int N = board.size(), num = 1, parity = 0;
        unordered_map<int, int> ladder;

        for (int r=N-1; r>=0; r--) {
            if (parity == 0) {
                for (int c=0; c<N; c++) {
                    if (board[r][c] != -1) ladder[num] = board[r][c];
                    num++;
                }
            } else {
                for (int c=N-1; c>=0; c--) {
                    if (board[r][c] != -1) ladder[num] = board[r][c];
                    num++;
                }                
            }
            parity = 1 - parity;
        }
        
        queue<int> q;
        q.push(1);
        vector<bool> visited(N*N+1, false);
        int step = 0;

        while (!q.empty()) {
            int sz = q.size();
            while (sz-- > 0) {
                int curr = q.front();
                if (curr == N*N) return step;
                q.pop();
                if (visited[curr]) continue;
                visited[curr] = true;

                for (int i=1; i<=6; i++) {
                    int nxt = curr + i;
                    if (curr + i > N*N) break;
                    if (ladder.contains(nxt)) {
                        nxt = ladder[nxt];
                    }
                    q.push(nxt);
                }
            }
            step++;
        }

        return -1;
    }
};