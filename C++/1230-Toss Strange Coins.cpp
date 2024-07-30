// DFS + memoization
class Solution {
public:
    int N;
    double dfs(int idx, int head, vector<double>& prob, vector<vector<double>>& memo) {
        if (idx == N) {
            if (head != 0) return 0;
            return 1;
        }
        if (head < 0 || N-idx < head) return 0;
        if (memo[idx][head] != -1) return memo[idx][head];

        double curr = 0;
        curr += prob[idx]*dfs(idx+1, head-1, prob, memo) + (1-prob[idx])*dfs(idx+1, head, prob, memo);

        return memo[idx][head] = curr;
    }
    double probabilityOfHeads(vector<double>& prob, int target) {
        this->N = prob.size();

        vector<vector<double>> memo(N, vector<double>(target+1, -1));
        return dfs(0, target, prob, memo);
    }
};

// bottom-up DP
class Solution {
public:
    double probabilityOfHeads(vector<double>& prob, int target) {
        int N = prob.size();
        vector<vector<double>> dp(N+1, vector<double>(target+1, 0.0));
        dp[0][0] = 1;

        // dp[i][k] = prob[i]*dp[i-1][k-1] (if k > 0) + (1-prob[i])*dp[i-1][k]

        for (int i=0; i<N; i++) {
            int idx = i+1;

            for (int k=0; k<=target; k++) {
                if (k > idx) break;
                if (k+1<=target) dp[idx][k+1] += dp[idx-1][k]*prob[i];
                dp[idx][k] += dp[idx-1][k]*(1-prob[i]);
            }
        }

        return dp[N][target];
    }
};


// space optimization
class Solution {
public:
    double probabilityOfHeads(vector<double>& prob, int target) {
        int N = prob.size();
        vector<double> dp(target+1, 0);
        dp[0] = 1;
        
        // dp[i][k] = prob[i]*dp[i-1][k-1] (if k > 0) + (1-prob[i])*dp[i-1][k]

        for (int i=0; i<N; i++) {
            for (int k = target; k>=0; k--) {
                dp[k] = (1-prob[i])*dp[k];
                if (k > 0) dp[k] += prob[i]*dp[k-1];
            }
        }

        return dp[target];
    }
};