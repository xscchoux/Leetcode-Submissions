class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        int N = piles.size();
        vector<vector<int>> dp(N, vector<int>(N, INT_MAX));

        // dp[i][j] : largest score difference

        for (int i=0; i<N; i++) {
            dp[i][i] = piles[i];
        }

        for (int len=1; len<N; len++) {
            for (int i=0; i<N; i++) {
                int j = i+len-1;
                if (i+len-1 < N) break;
                dp[i][j] = max(piles[i] - dp[i-1][j], piles[j] - dp[i][j-1]);
            }
        }

        return dp[0][N-1];
    }
};


class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        // when the length is even, alice can pick all odd-index stones or all even-index stones.
        // Note that the total number of stones is odd, a tie is impossible

        return true;
    }
};