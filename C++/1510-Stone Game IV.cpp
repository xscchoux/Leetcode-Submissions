class Solution {
public:
    bool dfs(int remain, vector<int>& squareNum, vector<int>& dp) {
        if (remain == 0) {
            return false;
        }

        if (dp[remain] != -1) {
            return dp[remain];
        }

        for (int i=0; i<squareNum.size() && squareNum[i] <= remain; i++) {
            if (!dfs(remain-squareNum[i], squareNum, dp)) {  // the opponent loses
                return dp[remain] = true;
            }
        }

        return dp[remain] = false;
    }
    bool winnerSquareGame(int n) {
         
        vector<int> squareNum;
        vector<int> dp(n+1, -1);

        for (int i=1; i*i <= n; i++) {
            squareNum.push_back(i*i);
        }

        int res = dfs(n, squareNum, dp);

        return res > 0;
    }
};


// clever iterative solution
class Solution {
public:
    bool winnerSquareGame(int n) {
        vector<bool> dp(n+1, false);  // dp[0] is always false because the player cannot make a move -> lose

        for (int i=1; i<=n; i++) {
            for (int k=1; k*k <= i; k++) {
                if (dp[i - k*k] == false) {
                    dp[i] = true;
                    break;
                }
            }
        }

        return dp[n];
    }
};