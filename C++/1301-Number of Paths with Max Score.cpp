class Solution {
private:
    static constexpr int kMod = 1e9+7;
public:
    int N;
    void update(vector<vector<pair<int, int>>>& dp, int currR, int currC, int prevR, int prevC) {
        if (prevR >= N || prevC >= N || dp[prevR][prevC].first == -1) {
            return;
        }

        if (dp[currR][currC].first < dp[prevR][prevC].first) {
            dp[currR][currC] = dp[prevR][prevC];
        } else if (dp[currR][currC].first == dp[prevR][prevC].first && dp[prevR][prevC].first != -1) {
            dp[currR][currC].second = (dp[currR][currC].second + dp[prevR][prevC].second)%kMod;
        }
    }
    vector<int> pathsWithMaxScore(vector<string>& board) {
        this->N = board.size();
        vector<vector<pair<int, int>>> dp(N, vector<pair<int, int>>(N, {-1, 0}));
        dp[N-1][N-1] = {0, 1};

        for (int r=N-1; r>=0; r--) {
            for (int c=N-1; c>=0; c--) {
                if (r == N-1 && c == N-1) continue;
                if (board[r][c] == 'X') continue;

                update(dp, r, c, r+1, c);
                update(dp, r, c, r, c+1);
                update(dp, r, c, r+1, c+1);
                if (dp[r][c].first != -1) {     // this is important!
                    dp[r][c].first += (board[r][c]=='E'?0:board[r][c]-'0');
                }
            }
        }

        if (dp[0][0].first == -1) {
            return {0, 0};
        }

        return {dp[0][0].first, dp[0][0].second};
    }
};